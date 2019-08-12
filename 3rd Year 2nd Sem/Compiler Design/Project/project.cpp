#include<bits/stdc++.h>
using namespace std;

map<string,string> symbols;
vector<pair<int,int> >rc;

// Function to populate the symbol mapping
void populateSym()
{
	fstream file2;
	string str;

	file2.open("mapping.txt", ios::in);
	while(getline(file2,str))
	{
		string first="";
		first+=str[0];
		symbols.insert(make_pair(first,str.substr(2)));
	}
	file2.close();
	// map<string,string>::iterator it;
	// for(it=symbols.begin();it!=symbols.end();it++)
	// 	cout<<it->first<<"\t\t"<<it->second<<endl;
}

// Function to print a production
void printProd(string prod)
{
	int i;
	// cout<<prod<<"\t\t\t\t";
	if(prod=="pop" || prod=="scan")
		return;

	string actual="";
	for(i=0;i<prod.length();i++)
	{
		string pr="";
		pr+=prod[i];
		if(i==1)
			actual+=" -> ";
		else if(symbols.find(pr)==symbols.end())// Trivial characters
			actual+=pr+" ";
		else
			actual+=symbols[pr]+" ";
	}
	cout<<actual;
}

void print(vector<pair<string,string> > v,vector<pair<int,int> >rcl){

	for(int i=0;i<v.size();i++){
		cout<<v[i].first<<"\t\t";
		if(symbols.find(v[i].second)==symbols.end())
				cout<<v[i].second<<"\t\t";
			else
				cout<<symbols[v[i].second]<<"\t\t";
		cout<<rcl[i].first<<"\t\t"<<rcl[i].second<<endl;
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
			mp.push_back(make_pair(v[i],"r"));
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
			mylist.push_back("q");
			mp.push_back(make_pair(v[i],"q"));
		}
		else if(v[i][0]=='('){
			mylist.push_back("x");
			mp.push_back(make_pair(v[i],"x"));
		}
		else if(v[i]=="const"){
			mylist.push_back("c");
			mp.push_back(make_pair(v[i],"c"));
		}
		else if(v[i]=="?" || v[i]==":"){
			mylist.push_back(v[i]);
			mp.push_back(make_pair(v[i],v[i]));
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
		else if((v[i][0]>='0' && v[i][0]<='9') || (v[i][0]=='-' && v[i][1]>='0' && v[i][1]<='9')){
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
	if(c==',' || c==';' || c==' ' || c=='\t' || c=='\n' || c=='?' || c==':' || c=='=' || c=='>' || c=='<' || c=='+' || c=='*')
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
					if(p[i]=='.'){
						if((p[i-1]>='0' && p[i-1]<='9') && (p[i+1]>='0' && p[i+1]<='9'))
							temp=temp+string(1,p[i]);
							if(i==p.length()-1){
							store.push_back(temp);
							int len123=temp.size();
							rc.push_back(make_pair(j+1,store_i+2-len123));
						}
						else{
							store.push_back(string(1,p[i]));
							rc.push_back(make_pair(j+1,store_i+1));
						}
					}
					else if(p[i]=='-'){
						if((p[i-1]=='=' || p[i-1]=='<' || p[i-1]=='>') && (p[i+1]>='0' && p[i+1]<='9'))
							temp=temp+string(1,p[i]);
							if(i==p.length()-1){
							store.push_back(temp);
							int len123=temp.size();
							rc.push_back(make_pair(j+1,store_i+2-len123));
						}
						else{
							store.push_back(string(1,p[i]));
							rc.push_back(make_pair(j+1,store_i+1));
						}
					}
					else{
						store.push_back(string(1,p[i]));
						rc.push_back(make_pair(j+1,store_i+1));
					}
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


// Function to print stack
void printStack(stack<char> st)
{
	stack<char> temp;
	string stack="";
	while(!st.empty())
	{
		temp.push(st.top());
		st.pop();
	}
	while(!temp.empty())
	{
		st.push(temp.top());
		stack+=temp.top();
		temp.pop();
	}
	cout<<"Stack: "<<stack<<endl;
}

// Function to parse a string
void parse(map< pair<char, char>, string > table, vector<string> expr, char startSym)
{
	// Create the stack and push $
	stack<char> st;
	st.push('$');
	// Push start symbol onto stack
	st.push(startSym);

	int i=0,j;
	while(!st.empty() && i<expr.size())
	{
		// First check if appropriate production exists
		pair<char,char> temp;
		char ch=expr[i][0];

		temp=make_pair(st.top(),ch);
		// cout<<temp.first<<", "<<temp.second;

		// Check if there is a match
		if(st.top()==ch)
		{
			cout<<"Action: match, Popping "<<st.top()<<"\t\t\t\t\t\t\t\t";
			if(symbols.find(expr[i])==symbols.end())
				cout<<expr[i]<<"\t\t\t\t";
			else
				cout<<symbols[expr[i]]<<"\t\t\t\t";
			printStack(st);

			i++;
			st.pop();
			continue;
		}
		if(table.find(temp)==table.end())
		{
			cout<<"Parse Error"<<endl;
			break;
		}
		else 
		if(table[temp]=="scan" || table[temp]=="pop")// If valid production not found then error
		{
			cout<<"Parse error at: "<<rc[i].first<<":"<<rc[i].second<<endl;
			if(table[temp]=="scan")
			{	
				cout<<"Scan"<<endl;
				i++;
				continue;
			}
			else if(table[temp]=="pop")
			{
				cout<<"Pop"<<endl;
				if(st.top()=='$')
					st.push('S');
				else
					st.pop();
				printStack(st);
				continue;
			}
		}
		

		// If valid production exists
		string pr=table[temp];
		cout<<"Action: Applying \t\t\t";
		printProd(pr);
		// cout<<pr;
		cout<<"Popping "<<st.top()<<"\t\t";
		// if(symbols.find(expr[i])==symbols.end())
		// 		cout<<expr[i]<<"\t\t\t\t\t";
		// 	else
		// 		cout<<symbols[expr[i]]<<"\t\t\t\t\t";
		cout<<expr[i]<<"\t\t\t\t\t";
		printStack(st);
		st.pop();

		if(pr[2]!='#')
			// push string onto stack
			for(j=pr.length()-1;j>=2;j--)
				st.push(pr[j]);
	}

}

int main(int argc, char const *argv[])
{
	populateSym();

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

	store=extract(store,rc);

	vector<string> tokens;
	vector<string> vars;
	tokens=my(store,vars,rc); //tokens are stored as per converted rules

	// ============= Parsing =======================

	cout<<"Parsing\n";
	
	// Create parsing table
	int i,j,num;
	char start;
	// cout<<"Enter number of entries in table"<<endl;
	cin>>num;
	cout<<num<<endl;
	map< pair<char, char>, string > parsingTab;
	// Take input
	// cout<<"For every entry first line is the non terminal second terminal third the production"<<endl;
	for(i=0;i<num;i++)
	{
		char nonter,ter;
		string prod;

		cin>>nonter;
		cin>>ter;
		cin>>prod;

		parsingTab[make_pair(nonter,ter)]=prod;

	}

	
	cin>>start;

	tokens.push_back("$");

	parse(parsingTab,tokens,start);

	return 0;
}