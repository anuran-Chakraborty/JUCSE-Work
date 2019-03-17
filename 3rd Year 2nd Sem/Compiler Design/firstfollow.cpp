#include<bits/stdc++.h>
using namespace std;

map<char, set<char> > firstSet;
map<char, set<char> > followSet;
int noofProd;
string* production;
vector<string> prod;


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
				if(production[i][j+1]!='\0')// It is not the ending character
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
				if(production[i][j+1]=='\0' && c!=production[i][0]) 
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

set<string> getClosure(char c)
{
	int i;
	set<string> closure;
	if(!isupper(c))// If non terminal return nothing
	{
		return closure;
	}

	for(i=0;i<noofProd;i++)
	{
		if(production[i][0]==c)// Then add this production
		{
			string aug=production[i].substr(0,2)+'.'+production[i].substr(2);
			closure.insert(aug);
			if(production[i][2]!=c)
			{
				set<string> temp=getClosure(production[i][2]);
				closure.insert(temp.begin(),temp.end());
			}
		}
	}
	return closure;
}

// Function to calculate I0 itemset
void calcI0()
{
	set<string> i0;
	// Insert the augmented production
	i0=getClosure(production[0][0]);

	// Print the closure
	set<string>::iterator it;
	for(it=i0.begin();it!=i0.end();it++)
		cout<<*it<<endl;
}

// Function to calculate goto
void calcgoto(set<string> item, char c)
{
	set<string> gotoset;
	set<string>::iterator it;
	for(it=item.begin();it!=item.end();it++)
	{
		string st=*it;
		
		if(st[st.find('.')+1]==c)
		{
			// First shift the . and add
			string temp;
			if(st.find('.')!=(st.length()-1))
			{
				temp=st.substr(0,st.find('.'))+st[st.find('.')+1]+'.'+st.substr(st.find('.')+2);
				gotoset.insert(temp);
				// Then calculate closure
				if((temp.find('.')+1)!=(temp.length()))
				{
					char s=temp[temp.find('.')+1];
					set<string> t=getClosure(s);
					gotoset.insert(t.begin(),t.end());
				}
			}
		}
	}

	for(it=gotoset.begin();it!=gotoset.end();it++)
		cout<<*it<<endl;
}

int main(int argc, char const *argv[])
{
	int i,j;
	printf("Enter number of productions\n");
	cin>>noofProd;
	printf("Enter the productions individually\n");

	production=new string[noofProd];
	for(i=0;i<noofProd;i++)
		cin>>production[i];

	// removeLeftRecur();
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

	// Printing first set
	for(it=firstSet.begin();it!=firstSet.end();it++)
	{
		cout<<"first("<<it->first<<") : {";
		for(its=it->second.begin();its!=it->second.end();its++)
			cout<<*its<<" ";
		cout<<"}\n";
	}
	cout<<"====================================\n";

	// for(i=0;i<noofProd;i++)
	// 	follow(production[i][0]);

	// // Printing first set
	// for(it=followSet.begin();it!=followSet.end();it++)
	// {
	// 	cout<<"follow("<<it->first<<") : {";
	// 	it->second.erase('#');
	// 	for(its=it->second.begin();its!=it->second.end();its++)
	// 		cout<<*its<<" ";
	// 	cout<<"}\n";
	// }

	// Print LR(0) itemset I0
	// calcI0();


	// Calculate goto
	// cout<<"Enter number of elements in itemset"<<endl;
	// int numitem;
	// cin>>numitem;

	// cout<<"Enter the itemset";
	// set<string> itemseti;
	// for(i=0;i<numitem;i++)
	// {
	// 	string str;
	// 	cin>>str;
	// 	itemseti.insert(str);
	// }

	// cout<<"Enter character to print goto of"<<endl;
	// char c;
	// cin>>c;

	// calcgoto(itemseti,c);

	return 0;
}