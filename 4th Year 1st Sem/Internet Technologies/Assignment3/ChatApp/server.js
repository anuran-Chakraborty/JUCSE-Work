var express=require('express'),
	app=express(),
	server=require('http').createServer(app),
	io=require('socket.io').listen(server);
	usernames=[];
var fs=require('fs');

server.listen(process.env.PORT || 3000)
console.log('Server running');


app.get('/', function(req,res){
	res.sendFile(__dirname+"/index.html");
});


io.sockets.on('connection',function(socket)
{
	console.log('Socket connected');

	socket.on('new user',function(data, callback){
		if(usernames.indexOf(data)!=-1){
			callback(false);
		}
		else
		{
			callback(true);
			socket.username=data;
			usernames.push(socket.username);
			updateUserNames();

		}
	});

	function updateUserNames(){
		io.sockets.emit('usernames',usernames);
	}

	//Send message
	socket.on('send message', function(data){
		io.sockets.emit('new message',{'msg':data,'user':socket.username});
	});

	socket.on('img message', function(msg){

		console.log(msg)
		var base64data = msg.image.replace(/^data:image\/png;base64,/,"");
		fs.writeFile('image.png', base64data, 'base64', (err) =>{
			if (err) throw err;
			console.log("The file has been saved");
			fs.readFile(__dirname+'/image.png', function(err, data){
				console.log("sending");
			    io.sockets.emit('imageConversionByServer', {user : socket.username, img : "data:image/png;base64,"+ data.toString("base64")});
			});
		});
		
	});

	socket.on('disconnect', function(data){
		if(!socket.username){
			return;
		}

		usernames.splice(usernames.indexOf(socket.username),1);
		updateUserNames();
	})	
});