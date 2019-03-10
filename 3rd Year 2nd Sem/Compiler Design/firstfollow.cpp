#include<bits/stdc++.h>
using namespace std;

map<char, set<char> > firstSet;
map<char, set<char> > followSet;
int noofProd;
string* production;

// Function to calculate first for a symbol
void first(char c,int q1,int q2)
{
	int j;

	// Case for terminal
	if(!isupper(c))
	{
		firstSet[c].insert(c);
	}
	// For all the productions
	for(j=0;j<noofProd;j++)
	{
		if(production[j][0]==c)// If the production has c on LHS then only calclulate
		{
			if(production[j][2]=='#') // If production is epsilon then recur for the next symbol
			{
				if(production[q1][q2]=='\0')// If epsilon is the only symbol add epsilon
				{
					firstSet[c].insert('#');
				}
				else if(production[q1][q2]!='\0' && (q1!=0 || q2!=0))// If there are other symbols
				{
					first(production[q1][q2],q1,q2+1);
					firstSet[c].insert(firstSet[production[q1][q2]].begin(),firstSet[production[q1][q2]].end());// Add to set
				}
				else
				{
					firstSet[c].insert('#');
				}

			}
			else if(!isupper(production[j][2])) // If start symbol is a terminal the forst is the start symbol
			{
				firstSet[c].insert(production[j][2]);
			}
			else // If it is a non-terminal then first calculate the first 
			{
				first(production[j][2],j,3);
				firstSet[c].insert(firstSet[production[j][2]].begin(),firstSet[production[j][2]].end());// Add to set
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	int i;
	printf("Enter number of productions\n");
	cin>>noofProd;
	printf("Enter the productions individually\n");

	production=new string[noofProd];
	for(i=0;i<noofProd;i++)
		cin>>production[i];

	for(i=0;i<noofProd;i++)
		first(production[i][0],0,0);

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

	return 0;
}