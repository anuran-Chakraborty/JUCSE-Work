#include<bits/stdc++.h>

using namespace std;

// Define the structure of the tree
typedef struct tree
{
	char symbol;
	int pos;	// position of the node a value of -1 indicates it is an operator
	vector<int> firstpos; // Store the first pos
	vector<int> lastpos; // Store the lastpos
	bool nullable;
	struct tree* left;
	struct tree* right;
} Tree;

string preprocess(string regex);
string infix_to_postfix(string regex);
int prec(char c);
Tree* construct_syntax_tree(string postfix);
void PrintVec(vector<int> vec);
bool isOp(char c);
map< pair<char, char>, pair<char, int> > dfa_from_tree(Tree* root);


int gpos, fl_pos, index_of_sentinel; // For index of follow pos
map<int, char> alpha_int; // Mapping of position with alpha
set<char> symbols; // Set of all input symbols
map<int, vector<int> > followpos; // Stores followpos correspoding to every node no



// For union of vectors
vector<int> operator +(vector<int> a, vector<int> b)
{
	a.insert(a.end(), b.begin(), b.end());
	sort(a.begin(), a.end());
	// Find unique
	a.erase(unique(a.begin(),a.end()),a.end()); //for finding unique element within vector
	return a;
}

int main()
{
	string regex, post_regex;
	printf("Enter a regular expression\n");
	getline(cin, regex); //Regex contains the regular expression
	regex=preprocess(regex); // Remove spaces from regex if it contains any
	regex=regex+".#"; // Add the sentinel
	cout<<regex<<endl;
	// Convert the regular expression from infix to postfix
	post_regex=infix_to_postfix(regex);
	cout<<post_regex<<endl;
	//Construct syntax tree from the postfix expression of regex
	Tree* node=construct_syntax_tree(post_regex);
	// Printing the followpos
	cout<<"Followpos"<<endl;
	map<int, vector<int> >::iterator i;
	for(i=followpos.begin();i!=followpos.end();i++)
	{
		cout<<i->first<<"\t";
		PrintVec(i->second);
		cout<<endl;
	}
	// Construct dfa from the tree
	dfa_from_tree(node);
	// Print the dfa
	return 0;
}

// Function to check if operator
bool isOp(char c)
{
	return (c=='|' || c=='*' || c=='(' || c==')' || c=='+' || c=='.');
}
// Function to remove spaces and + and add . from regex
string preprocess(string regex)
{
	string nregex="";
	int i=0;
	for(i=0;i<regex.length();i++)
	{
		if(regex[i]==' ')
			continue;
		else
		if(regex[i]=='+') // If + convert to *
		{
			nregex=nregex+regex[i-1];
			nregex+=".";
			nregex+=regex[i-1];
			nregex+="*";
		}
		// Insert concat operator for *
		else
		if(regex[i]=='*' || (regex[i]==')' && i<regex.length()-1 && !isOp(regex[i+1])))
		{
			nregex+=regex[i];
			nregex+=".";
		}
		// Insert concat for opening bracket
		else
		if(i<regex.length()-1 && regex[i]=='(' && i!=0)
		{
			nregex+=".";
			nregex+=regex[i];
		}
		else
		if(!isOp(regex[i]))
		{
			if(i<regex.length()-1 && !isOp(regex[i+1])) // If the next character is also not an operator concat
			{
				nregex+=regex[i];
				nregex+=".";
			}
			else
				nregex+=regex[i]; 
		}
		else
			nregex+=regex[i]; 
	}
	return nregex;
}
// Function to return precedence of operators
int prec(char c)
{
	if(c=='*')
		return 3;
	if(c=='|')
		return 2;
	if(c=='.')
		return 1;
	else
		return -1;
}
// Function to convert expression from infix to postfix
string infix_to_postfix(string regex)
{
	string post_regex="";
	stack<char> st;
	int l = regex.length(), i;

    for(i=0;i<l;i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if((regex[i] >= 'a' && regex[i] <= 'z')||(regex[i] >= 'A' && regex[i] <= 'Z')||(regex[i] >= '0' && regex[i] <= '9') || regex[i]=='#') 
        	post_regex+=regex[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(regex[i] == '(')         
        	st.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(regex[i] == ')') 
        { 
            while(!st.empty() && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               	post_regex+=c; 
            } 
            if(st.top() == '(') 
            {  
                st.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else
        { 
            while(!st.empty() && prec(regex[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                post_regex += c; 
            } 
            st.push(regex[i]); 
        } 
    }
    //Pop all the remaining elements from the stack 
    while(!st.empty()) 
    { 

        char c = st.top(); 
        st.pop(); 
        post_regex += c; 
    }
    return post_regex;
}

// Function to create a tree node
Tree* newnode(char sym, int posi)
{
	Tree* node=new Tree;
	node->symbol=sym;
	node->pos=posi;
	node->left=node->right=NULL;
	node->firstpos.clear();
	node->lastpos.clear();
	return node;
}
// Construct syntax tree from postfix expression
Tree* construct_syntax_tree(string postfix)
{
	Tree* root;
	int i, j;
	stack<Tree*> s;

	// Building syntax tree
	for(i=0;i<postfix.length();i++)
	{
		// Case if not an operator
		if(!isOp(postfix[i]))
		{
			gpos++;
			if(postfix[i]!='#')
			{
				fl_pos++;
				alpha_int[fl_pos]=postfix[i];
				symbols.insert(postfix[i]);
			}
			else
				index_of_sentinel=gpos;

			root=newnode(postfix[i],gpos);
			root->nullable=false;
			root->firstpos.push_back(gpos);
			root->lastpos.push_back(gpos);
		}
		// case for * operator
		else
		if(postfix[i]=='*')
		{
			root=newnode(postfix[i],-1);
			root->left=s.top();
			s.pop();
			root->nullable=true;
			root->firstpos=root->left->firstpos;
			root->lastpos=root->left->lastpos;

			// Calculating followpos
			for(j=0;j<root->lastpos.size();j++)
			{
				followpos[root->lastpos[j]]=followpos[root->lastpos[j]]+root->firstpos;
			}

		}
		// case for concatenation
		else
		if(postfix[i]=='.')
		{
			root=newnode(postfix[i],-1);
			root->right=s.top();
			s.pop();
			root->left=s.top();
			s.pop();
			root->nullable=(root->left->nullable)&&(root->right->nullable);

			// Insert firstpos
			if(root->left->nullable)
			{
				root->firstpos=root->left->firstpos+root->right->firstpos;
			}
			else
				root->firstpos=root->left->firstpos;

			// Insert lastpos
			if(root->right->nullable)
			{
				root->lastpos=root->left->lastpos+root->right->lastpos;
			}
			else
				root->lastpos=root->right->lastpos;

			// Calculating followpos
			for(j=0;j<root->left->lastpos.size();j++)
			{
				followpos[root->left->lastpos[j]]=followpos[root->left->lastpos[j]]+root->right->firstpos;
			}

		}
		// case for union
		else
		if(postfix[i]=='|')
		{
			root=newnode(postfix[i],-1);
			root->right=s.top();
			s.pop();
			root->left=s.top();
			s.pop();
			root->nullable=(root->left->nullable)||(root->right->nullable);

			root->firstpos=root->left->firstpos+root->right->firstpos;

			root->lastpos=root->left->lastpos+root->right->lastpos;
		}
		// For all other cases
		s.push(root);
	}
	return root;
}

// Construct dfa from syntax tree
map< pair<char, char>, pair<char, int> > dfa_from_tree(Tree* root)
{
	// Keep a map for set of position to states
	map<vector<int>, pair<char, int> > dStates; // The int value indicates start(1) final(2) or intermediate(0) state
	map<vector<int>, pair<char, int> >::iterator dsit;

	// Dfa can be a map of state and symbol with next state
	map< pair<char, char>, pair<char, int> > dfa;
	map< pair<char, char>, pair<char, int> >::iterator dfait;

	map<int, char>::iterator it;
	vector<int> mu;
	vector<int> states;

	set<char>::iterator symit;

	char ch='A';
	int i,j, p, curr_state, num_states;
	dStates[root->firstpos]=make_pair(ch++,1); // 1 indicates start state

	for(dsit=dStates.begin(); dsit!=dStates.end(); dsit++)
	{
		// dsit correspond to a state S
		for(symit=symbols.begin(); symit!=symbols.end();symit++)
		{
			mu.clear();
			// Take the union
			// dsit->first contains all states for union
			for(p=0;p<(dsit->first).size();p++)
			{
				// Take union if it corresponds to input alphabet
				// p[i]=is the position
				if(alpha_int[dsit->first[p]]==*symit)
				{
					mu=mu+followpos[dsit->first[p]];
				}
			}
			if(dStates.find(mu)==dStates.end()) // if mu not in dStates
			{
				// Add mu to dStates
				// Check if mu is final state
				int final_st=0;
				for(j=0;j<mu.size();j++)
					if(mu[j]==index_of_sentinel) // Final state is this
					{
						final_st=2;
						break;
					}

				dStates[mu]=make_pair(ch++,final_st);
			}
			// Add the transition
			dfa[make_pair(dsit->second.first, *symit)]=dStates[mu];
		}
	}
	cout<< "The states are"<<endl;
	for(dsit=dStates.begin(); dsit!=dStates.end(); dsit++)
	{
		PrintVec(dsit->first);
		cout<<"\t"<<dsit->second.first<<endl;
	}

	cout<<"The dfa is"<<endl;
	// Print the dfa
	for(dfait=dfa.begin(); dfait!=dfa.end(); dfait++)
	{
		if(dfait->second.second==1)
			cout<<dfait->first.first<<"(start)"<<"\t"<<dfait->first.second<<"\t"<<dfait->second.first<<endl;
		else
		if(dfait->second.second==2)
			cout<<dfait->first.first<<"(final)"<<"\t"<<dfait->first.second<<"\t"<<dfait->second.first<<endl;
		else
			cout<<dfait->first.first<<"\t"<<dfait->first.second<<"\t"<<dfait->second.first<<endl;
	}
	return dfa;
}
// Fucntion to print a vector
void PrintVec(vector<int> vec)
{
	int i=0;
	for(i=0;i<vec.size();i++)
		cout<<vec[i]<<",";
}