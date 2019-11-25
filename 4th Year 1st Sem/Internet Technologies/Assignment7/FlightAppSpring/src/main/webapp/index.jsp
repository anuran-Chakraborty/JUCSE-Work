<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta charset="ISO-8859-1">
	<title>Login</title>

	<style type="text/css">
		
		body{
			background-color: #a2a2a2;
		}

		#login-page{
			width:360px;
			padding:10% 0 0;
			margin:auto;
		}

		#formAll{
			position: relative;
			z-index: 100;
			background: #ffffff;
			max-width: 360px;
			margin: 0 auto 100px;
			padding: 45px;
			text-align: center;
		}

		select, input{
			font-family: "Times New Roman", serif;
			outline:1;
			background: #f2f2f2;
			width: 100%;
			border: 0;
			margin: 0 0 15px;
			padding: 15px;
			box-sizing: border-box;
			font-size: 14p;
		}

		#submit{
			text-transform: uppercase;
			padding: 15px;
			color: #FFFFFF;
			background: #000000;
			cursor: pointer;
		}

		.register-Form{
			display: none;
		}
		
		.forgot-pass-form{
			display: none;
		}

		#duplicateUname{
			display:none;
			color: red;
			
		}

	</style>

	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js">
	</script>

	
	

</head>


<body>

	<div id="login-page">
		<div id="form">
			<form id="loginform formAll" class="loginform" action="login" method="post">
				<input type="text" name="username" required="" placeholder="Enter your Username"><br>
				<input type="password" name="password" required="" placeholder="Enter your password"><br>
				<input type="submit" id="submit" name="submit" value="Login">
				<p class="notReg"> Not registered? <a class="reg-here" href="#">Register Here </a></p>
				
			</form>
		
			<form id="reg formAll" class="register-Form" action="register" method="post">
				<input type="text" name="name" required="" placeholder="Enter your name"><br>

				<div id="duplicateUname">Sorry, this username is already taken</div>
				
				<input type="text" name="username" placeholder="Enter your Username"><br>
				<input type="password" name="password" placeholder="Enter your password"><br>

				<input type="submit" id="submit" name="submit" value="Register">
				<p class="alreadyReg"> Already registered? <a class="login-here" href="#">Login Here </a></p>
			</form>

			<form id="forgot formAll" class="forgot-pass-form" action="forgot" method="post">
				<input type="text" name="username" placeholder="Enter your username">
				<input type="password" name="password" placeholder="Enter new password"> 
				<input type="submit" name="submit" id="submit" value="Change Password">
			</form>
			
		</div>
	</div>

</body>

<script type="text/javascript">
		$(document).ready(function(){
			$('.reg-here').click(function(){
				$('.loginform').hide();
				$('.forgot-pass-form').hide();
				$('.register-Form').show();
			});

			$('.forgot-pass').click(function(){
				$('.loginform').hide();
				$('.forgot-pass-form').show();
				$('.register-Form').hide();
			})

			$('.login-here').click(function(){
				$('.loginform').show();
				$('.forgot-pass-form').hide();
				$('.register-Form').hide();
			});
		});

</script>

</html>