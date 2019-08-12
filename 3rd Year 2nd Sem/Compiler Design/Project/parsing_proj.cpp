#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;

map<char, set<char> > firstSet;
map<char, set<char> > followSet;
map< pair<char,char>, string > table;
int noofProd;
string* production;
vector<string> prod;
set<char> t,nt;

int conflict;

map<char,string> symbols;

// Function to populate the symbol mapping
void populateSym()
{
	fstream file2;
	string str;

	file2.open("mapping.txt", ios::in);
	while(getline(file2,str))
	{
		// string first="";
		// first+=str[0];
		symbols.insert(make_pair(str[0],str.substr(2)));
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
	{
		cout<<prod;
		return;
	}

	string actual="";
	for(i=0;i<prod.length();i++)
	{
		string pr="";
		pr+=prod[i];
		if(i==1)
			actual+=" -> ";
		else if(symbols.find(prod[i])==symbols.end())// Trivial characters
			actual+=pr+" ";
		else
			actual+=symbols[prod[i]]+" ";
	}
	cout<<actual;
}

// Function to remove left recursion
void removeLeftRecur()
{
	int i,j;
	for(i=0;i<noofProd;i++)
	{
		int nextind=i;
		// If this produciton has a left recursion
		if(production[i][0]==production[i][2])
		{
			// Then try removing it
			string newprod="";
			newprod+=production[i][0];
			newprod+='\'';
			// For every produciton having X in the 2 index
			for(j=0;j<noofProd;j++)
			{
				if(production[j][0]==production[i][0] && production[j][0]!=production[j][2])
				{
					// Remove the first part
					prod.push_back(production[j]+newprod);
					nextind=j;
				}
				else if(production[j][0]==production[i][0] && production[j][0]==production[j][2])
				{
					string nstr=production[j].substr(3);
					string nstr2=newprod+'=';
					prod.push_back(nstr2+nstr+newprod);
					nextind=j;
				}
			}
			// Push epsilon
			string ns=newprod+'='+'#';
			prod.push_back(ns);	
		}
		else
			prod.push_back(production[i]);
		i=nextind;
	}
}

// Function to calculate first for a symbol
void first(char c, int rule_no)
{
	int j,k;

	// Case for terminal
	if(!isupper(c))
	{
		firstSet[c].insert(c);
	}
	// For all the productions
	for(j=rule_no;j<noofProd;j++)
	{
		if(production[j][0]==c)// If the production has c on LHS then only calclulate
		{
			if(production[j][2]=='#') // If production is epsilon then recur for the next symbol
			{
				firstSet[c].insert('#');
			}
			else if(!isupper(production[j][2])) // If start symbol is a terminal the first is the start symbol
			{
				firstSet[c].insert(production[j][2]);
			}
			else // If it is a non-terminal then first calculate its firstset 
			{
				for(k=2;k<production[j].length();k++)
				{
					// If it is a terminal simply add the terminal
					if(!isupper(production[j][k]))
					{
						firstSet[c].insert(production[j][k]);
						break;
					}
					else
					{
						if(production[j][k]!=c)
						{
							// If it is a nonterminal calculate its first
							first(production[j][k],0);
							// Add the first set to it
							firstSet[c].insert(firstSet[production[j][k]].begin(),firstSet[production[j][k]].end());
							// If epsilon not in this then break
							if(firstSet[production[j][k]].find('#')==firstSet[production[j][k]].end())
								break;
							else
								// remove #
								firstSet[c].erase('#');
						}
						else
						{
							// Check if present symbol first has epsilon
							first(production[j][k],j+1);
							if(firstSet[production[j][k]].find('#')==firstSet[production[j][k]].end())
								break;
						}

					}
				}
				// If last contains # add #
				if(k==production[j].length())
					firstSet[c].insert('#');
			}
		}
	}

}

// Function to calculate follow
void follow(char c)
{
	int i,j,k;
	// First add $ to follow set of start symbol
	if(production[0][0]==c)
		followSet[c].insert('$');
	// For every production
	for(i=0;i<noofProd;i++)
	{
		// Now traverse every production
		for(j=2;j<production[i].length();j++)
		{
			if(production[i][j]==c) // If c found on RHS
			{
				if(j!=(production[i].length()-1))// It is not the ending character
				{
					// Insert the first of next non terminal
					followSet[c].insert(firstSet[production[i][j+1]].begin(),firstSet[production[i][j+1]].end());
					for(k=j+1;k<production[i].length();)
					{
						if(firstSet[production[i][k]].find('#')==firstSet[production[i][k]].end())// If epsilon does not exist then break
							break;
						k++;
						if(k==production[i].length())
							break;
						followSet[c].insert(firstSet[production[i][k]].begin(),firstSet[production[i][k]].end());
					}
					// If even the last symbol has epsilon in its first then compute follow of LHS
					if(k==production[i].length())
					{
						if(c!=production[i][0]) 
		                { 
		                    // Calculate the follow of the Non-Terminal 
		                    // in the L.H.S. of the production 
		                    follow(production[i][0]);
		                    // Insert into set
		                    followSet[c].insert(followSet[production[i][0]].begin(),followSet[production[i][0]].end());
		                }
					}
				}
				else
				// For ending character add follow of LHS
				if(j==(production[i].length()-1) && c!=production[i][0]) 
                { 
                    // Calculate the follow of the Non-Terminal 
                    // in the L.H.S. of the production 
                    follow(production[i][0]);
                    // Insert into set
                    followSet[c].insert(followSet[production[i][0]].begin(),followSet[production[i][0]].end());
                } 
				
			}

		}
	}
}

void fill_t_nt(){
	vector<string>::iterator i;
	string s;
	for(i=prod.begin();i!=prod.end();i++){
		nt.insert((*i)[0]);
	}

	t.insert('#');
	t.insert('$');

	for(i=prod.begin();i!=prod.end();i++){
		s=(*i);
		for(int j=2;j<s.length();j++){
			if(nt.find(s[j])==nt.end()){
				t.insert(s[j]);
			}
		}
	}
}

void make_table(){

	vector<string>::iterator prodit;
	string rule;

	conflict=0;
	
	for(prodit = prod.begin(); prodit!= prod.end(); prodit++){
		rule = *(prodit);
		int i;
		for(i=2;i<rule.length();i++){
			set<char> first = firstSet[rule[i]];
			set<char>::iterator it;
			int flag = 1; //check whether current character in rhs of rule has epsilon 

			for(it = first.begin(); it!=first.end(); it++){
				if((*it)=='#'){
					flag = 0; 
				}
				else{
					if(table.find(make_pair(rule[0],(*it)))!=table.end() && table[make_pair(rule[0],(*it))]!=rule){
						cout<<"Error 1 at "<<rule[0]<<","<<(*it)<<","<<rule<<","<<table[make_pair(rule[0],*it)]<<endl;
						conflict=1;
						return;
					}
					table[make_pair(rule[0],(*it))] = rule;
				}
			}
			if(flag){   //if epsilon is not present, this rule is not needed any more.
				break;
			}
		}

		if(i == rule.length()){  //the entire rhs has epsilon in first. so followSet of lhs is used.
			set<char> fol = followSet[rule[0]];
			set<char>::iterator it;

			for(it = fol.begin(); it!=fol.end(); it++){
				if(table.find(make_pair(rule[0],(*it)))!=table.end() && table[make_pair(rule[0],(*it))]!=rule){
						cout<<"Error 2 at "<<rule[0]<<","<<(*it)<<","<<rule<<","<<table[make_pair(rule[0],*it)]<<endl;
						conflict=1;
						return;
				}
				table[make_pair(rule[0],(*it))] = rule;
			}
		}
	}

	set<char>::iterator itt,itnt;
	// cout<<"Non-terminal\tTerminal\tRule\n";
	// for(itnt = nt.begin(); itnt!=nt.end();itnt++){  //non terminal loop
	// 	for(itt = t.begin(); itt!=t.end();itt++){   //terminal loop
	// 		cout<<(*itnt)<<"\t"<<(*itt)<<"\t"<<table[make_pair(*itnt,*itt)]<<"\n";
	// 	}
	// 	cout<<endl;
	// }

	//set<char>::iterator itt, itnt; 
	for(itnt = nt.begin(); itnt!=nt.end();itnt++){  //non terminal loop
		for(itt = t.begin(); itt!=t.end();itt++){   //terminal loop
			if(table.count(make_pair(*itnt,*itt))==0){
			//if(table.find( make_pair( (*itnt),(*itt) ) ) == table.end()){
				if((*itt)=='$' || followSet[(*itnt)].find((*itt))!=followSet[(*itnt)].end()){
					table[make_pair((*itnt),(*itt))] = "pop";
				}
				else if(firstSet[(*itnt)].find((*itt))==firstSet[(*itnt)].end() && followSet[(*itnt)].find((*itt))==followSet[(*itnt)].end()){
					table[make_pair((*itnt),(*itt))] = "scan";
				}
			}
		}
	}

}


int main(int argc, char const *argv[])
{
	int i,j;
	printf("Enter number of productions\n");
	cin>>noofProd;
	printf("Enter the productions individually\n");

	populateSym();

	production=new string[noofProd];
	for(i=0;i<noofProd;i++)
		cin>>production[i];

	removeLeftRecur();
	fill_t_nt();
	// for(i=0;i<prod.size();i++)
	// 	cout<<prod[i]<<endl;

	// Insert first of terminals
	for(i=0;i<noofProd;i++)
		for(j=0;j<production[i].length();j++)
			if(!isupper(production[i][j]))// Terminal
				firstSet[production[i][j]].insert(production[i][j]);

	for(i=0;i<noofProd;i++)
		first(production[i][0],0);

	map<char, set<char> >::iterator it;
	set<char>::iterator its;

	cout<<"printing terminals"<<endl;
	for(its=t.begin();its!=t.end();its++)
	{
		if(symbols.find(*its)==symbols.end())
			cout<<*its<<endl;
		else
			cout<<symbols[*its]<<endl;
	}

	cout<<"printing non terminals"<<endl;
	for(its=nt.begin();its!=nt.end();its++)
	{
		if(symbols.find(*its)==symbols.end())
			cout<<*its<<endl;
		else
			cout<<symbols[*its]<<endl;
	}

	// Printing first set
	for(it=firstSet.begin();it!=firstSet.end();it++)
	{
		cout<<"first(";
		if(symbols.find(it->first)==symbols.end())
			cout<<it->first<<"  ";
		else
			cout<<symbols[it->first];
		cout<<") : {";

		for(its=it->second.begin();its!=it->second.end();its++)
		{
			if(symbols.find(*its)==symbols.end())
				cout<<*its<<"  ";
			else
				cout<<symbols[*its]<<"  ";
		}
		cout<<"}\n";
	}
	cout<<"====================================\n";

	for(i=0;i<noofProd;i++)
		follow(production[i][0]);

	// Printing follow set
	for(it=followSet.begin();it!=followSet.end();it++)
	{
		cout<<"follow(";
		if(symbols.find(it->first)==symbols.end())
			cout<<it->first;
		else
			cout<<symbols[it->first];
		cout<<") : {";

		it->second.erase('#');
		for(its=it->second.begin();its!=it->second.end();its++)
		{
			if(symbols.find(*its)==symbols.end())
				cout<<*its<<"  ";
			else
				cout<<symbols[*its]<<"  ";
		}
		cout<<"}\n";
	}

	cout<<"====================================\n";

	make_table();

	if(conflict==0)
	{

		cout<<"Table making Done\nPrinting table\n\n";

		set<char>::iterator itt,itnt;
		cout<<"Non-terminal\tTerminal\tRule\n";
		for(itnt = nt.begin(); itnt!=nt.end();itnt++){  //non terminal loop
			for(itt = t.begin(); itt!=t.end();itt++)
			{   //terminal loop

				if(symbols.find(*itnt)==symbols.end())
					cout<<*itnt<<"\t";
				else
					cout<<symbols[*itnt]<<"\t";

				if(symbols.find(*itt)==symbols.end())
					cout<<*itt<<"\t";
				else
					cout<<symbols[*itt]<<"\t";

				printProd(table[make_pair(*itnt,*itt)]);

				cout<<"\n";
			}
			cout<<endl;
		}

		// Save parsing table to file
		fstream fout;
		fout.open("parsing_table.txt",ios::trunc | ios::out);
		int total=t.size()*nt.size();

		fout<<total<<endl;

		for(itnt = nt.begin(); itnt!=nt.end();itnt++){  //non terminal loop
			for(itt = t.begin(); itt!=t.end();itt++){   //terminal loop
				fout<<(*itnt)<<endl;
				fout<<(*itt)<<endl;
				fout<<table[make_pair(*itnt,*itt)]<<"\n";
			}
		}
		fout<<"S"<<endl;
		fout.close();
		cout<<"Parsing table written to file\n";
	}

	return 0;
}