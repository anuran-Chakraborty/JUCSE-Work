
/*main function e tokens r madhye converted tokens gula ache
	vars r madhhye variable names gula ache*/


#include<bits/stdc++.h>
using namespace std;


void print(vector<pair<string,string> > v,vector<pair<int,int> >rc){

	for(int i=0;i<v.size();i++){
		cout<<v[i].first<<"\t"<<v[i].second<<"\t\t"<<rc[i].first<<"\t"<<rc[i].second<<endl;
	}
}
void printvector(vector<string> a){
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<endl;
	}
}
vector<string> my(vector<string> v,vector<string> & vars,vector<pair<int,int> >rc){
	vector<string> mylist;
	//vector<string> vars;
	vector<pair<string,string> > mp;
	for(int i=0;i<v.size();i++){
		if(v[i]=="program"){
			mylist.push_back("p");
			mp.push_back(make_pair(v[i],"p"));
		}
		else if(v[i]=="uses"){
			mylist.push_back("l");
			mp.push_back(make_pair(v[i],"l"));
		}
		else if(v[i]=="real"){
			mylist.push_back("r");
			mp.push_back(make_pair(v[i],"l"));
		}
		else if(v[i]=="integer"){
			mylist.push_back("u");
			mp.push_back(make_pair(v[i],"u"));
		}
		else if(v[i]=="var"){
			mylist.push_back("v");
			mp.push_back(make_pair(v[i],"v"));
		}

		else if(v[i]=="function"){
			mylist.push_back("f");
			mp.push_back(make_pair(v[i],"f"));
		}
		else if(v[i]=="begin"){
			mylist.push_back("b");
			mp.push_back(make_pair(v[i],"b"));
		}
		else if(v[i]=="end"){
			mylist.push_back("e");
			mp.push_back(make_pair(v[i],"e"));
		}
		else if(v[i]=="get"){
			mylist.push_back("g");
			mp.push_back(make_pair(v[i],"g"));
		}
		else if(v[i]=="put"){
			mylist.push_back("p");
			mp.push_back(make_pair(v[i],"p"));
		}
		else if(v[i][0]=='('){
			mylist.push_back("x");
			mp.push_back(make_pair(v[i],"x"));
		}
		else if(v[i]=="const"){
			mylist.push_back("c");
			mp.push_back(make_pair(v[i],"c"));
		}
		else if(v[i]=="." || v[i]==";" || v[i]==","){
			mylist.push_back(v[i]);
			mp.push_back(make_pair(v[i],v[i]));
		}
		else if(v[i]=="==" || v[i]=="=" || v[i]=="<" || v[i]==">" || v[i]=="<=" || v[i]==">="){
			if(v[i]=="<="){
				mylist.push_back("y");
				mp.push_back(make_pair(v[i],"y"));
			}
			else if(v[i]==">="){
				mylist.push_back("z");
				mp.push_back(make_pair(v[i],"z"));
			}
			else{
				mylist.push_back(v[i]);
				mp.push_back(make_pair(v[i],v[i]));
			}
		}
		else if(v[i]=="+" || v[i]=="-" || v[i]=="*"){
			mylist.push_back(v[i]);
			mp.push_back(make_pair(v[i],v[i]));
		}
		else if(v[i][0]>='0' && v[i][0]<='9'){
			mylist.push_back("n");
			mp.push_back(make_pair(v[i],"n"));
		}
		else{
			if(v[i]!=""){
				mylist.push_back("i");
				mp.push_back(make_pair(v[i],"i"));
				vars.push_back(v[i]);
			}

		}


	}
	//cout<<"tokens\t converted\n";

	cout<<"token\tconverted token\trow\tcolumn\n";

	print(mp,rc);
	return mylist;


}

bool isdelim(char c){
	if(c==',' || c==';' || c=='.' || c==' ' || c=='\t' || c=='\n' || c=='?' || c==':' || c=='=' || c=='>' || c=='<' || c=='+' ||c=='-' || c=='*')
	return true;
	return false;
}
vector<string> extract(vector<string> s, vector<pair<int,int> >&rc){

	vector<string> store;

	for(int j=0;j<s.size();j++){
		string p=s[j];

		string temp="";
		int tab=0;
		int tag=0;

		for(int i=0;i<p.length();i++){
			//cout<<p[i]<<" ";
			int store_i=i;
			if(tag){
				store_i=tab+i;
			}
			if(isdelim(p[i])){
				if(temp.size()!=0){
					store.push_back(temp);
					int len123=temp.size();
					rc.push_back(make_pair(j+1,store_i+1-len123));
			}
				//cout<<temp<<endl;
				//while(i<p.length() && p[i]==' ')
				//	i++;
				if(p[i]==',' || p[i]==';' || p[i]=='?' || p[i]==':' || p[i]=='.' || p[i]=='=' || p[i]=='+' || p[i]=='-' || p[i]=='*'){
					store.push_back(string(1,p[i]));
					rc.push_back(make_pair(j+1,store_i+1));
				}
				else if(p[i]=='\t'){
					tab+=3;
					tag=1;
				}
				else if(p[i]=='<' && p[i+1]=='='){
					store.push_back("<=");
					rc.push_back(make_pair(j+1,store_i+1));
					i++;
				}
				else if(p[i]=='>' && p[i+1]=='='){
					store.push_back(">=");
					rc.push_back(make_pair(j+1,store_i+1));
					i++;
				
				}
				else if(p[i]=='>'){
					store.push_back(">");
					rc.push_back(make_pair(j+1,store_i+1));
				}

				else if(p[i]=='<'){
					store.push_back("<");
					rc.push_back(make_pair(j+1,store_i+1));
				}
				
				temp="";
			}

			else{

				if(p[i]=='('){
					rc.push_back(make_pair(j+1,store_i+1));
					string w="";
					while(p[i]!=')'){
						w=w+string(1,p[i]);
						i++;
					}
					w=w+string(1,p[i]);
					store.push_back(w);


				}
				else{
					temp=temp+string(1,p[i]);
					if(i==p.length()-1){
						store.push_back(temp);
						int len123=temp.size();
						rc.push_back(make_pair(j+1,store_i+2-len123));
						//rc.push_back(make_pair(j+1,i+1));
						//cout<<temp<<endl;
					}
				}
			}

		}
	}



	

	return store;


}


int main(){

	fstream file; 
	string word, t, q, filename; 

	 
	filename = "test.pas"; 

	file.open(filename.c_str()); 

	vector<string> store;
	
	string str;
	while(getline(file,str)){
		store.push_back(str.c_str());
	}
	printvector(store);

	vector<pair<int,int> >rc;

	store=extract(store,rc);



	
	vector<string> tokens;
	vector<string> vars;
	tokens=my(store,vars,rc); //tokens are stored as per converted rules
	cout<<"...converted...\n";

	//printvector(tokens);
	
	return 0; 
} 
