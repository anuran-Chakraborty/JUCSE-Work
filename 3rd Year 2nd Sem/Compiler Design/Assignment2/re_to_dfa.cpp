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
map< pair<char, char>, char > dfa_from_tree(Tree* root);
bool is_valid_string(string str, map< pair<char, char>, char > dfa);
void printTree(Tree* root);

int gpos, fl_pos, index_of_sentinel; // For index of follow pos
map<int, char> alpha_int; // Mapping of position with alpha
set<char> symbols; // Set of all input symbols
map<int, vector<int> > followpos; // Stores followpos correspoding to every node no
set<char> final_states;
char start_state;


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
	string regex, post_regex, str;
	printf("Enter a regular expression\n");
	getline(cin, regex); //Regex contains the regular expression
	regex=preprocess(regex); // Remove spaces from regex if it contains any
	regex=regex+".#"; // Add the sentinel
	// Convert the regular expression from infix to postfix
	post_regex=infix_to_postfix(regex);
	//Construct syntax tree from the postfix expression of regex
	Tree* node=construct_syntax_tree(post_regex);
	//Printing the tree
	cout<<"The syntax tree is"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Parent\t\t|Left Child\t|Right Child\t|Nullable\t|First Pos\t|Last pos\t|"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	printTree(node);
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
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
	map< pair<char, char>, char > dfa=dfa_from_tree(node);
	// Simulate the dfa on a string
	do
	{
		cout<<"Enter a string to check if it matches the regular expression... press enter to exit"<<endl;
		getline(cin,str);
		if(str=="" || str=="\n")
			break;
		if(is_valid_string(str,dfa))
			cout<<"String is accepted"<<endl;
		else
			cout<<"String is rejected"<<endl;
	}
	while(1);
	return 0;
}

// Function to check if operator
bool isOp(char c)
{
	return (c=='|' || c=='*' || c=='(' || c==')' || c=='+' || c=='.');
}

//Function to print the tree
void printTree(Tree* root)
{
	// Perform inorder traversal and pint parent and child
	if(!root)
		return;
	
	cout<<root->symbol<<"("<<root->pos<<")"<<"\t\t|";
	
	if(root->left)
		cout<<root->left->symbol<<"("<<root->left->pos<<")"<<"\t\t|";
	else
		cout<<" NA\t\t|";
	if(root->right)
		cout<<root->right->symbol<<"("<<root->right->pos<<")"<<"\t\t|";
	else
		cout<<" NA\t\t|";
	cout<<root->nullable<<"\t\t|";
	PrintVec(root->firstpos);
	cout<<"\t\t|";
	PrintVec(root->lastpos);
	cout<<"\t\t|"<<endl;

	printTree(root->left);
	printTree(root->right);
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
		// case for or
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
		s.push(root);
	}
	return root;
}

// Construct dfa from syntax tree
map< pair<char, char>, char > dfa_from_tree(Tree* root)
{
	// Keep a map for set of position to states
	map<vector<int>, char > dStates; // The int value indicates start(1) final(2) or intermediate(0) state
	map<vector<int>, char >::iterator dsit;

	// Dfa can be a map of state and symbol with next state
	map< pair<char, char>, char > dfa;
	map< pair<char, char>, char >::iterator dfait;

	map<int, char>::iterator it;
	vector<int> mu;
	vector<int> states;

	set<char>::iterator symit;

	char ch='A';
	int i,j, p;
	dStates[root->firstpos]=ch++; // 1 indicates start state
	start_state=dStates[root->firstpos];

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

				dStates[mu]=ch++;
				if(final_st==2)
					final_states.insert(dStates[mu]);
			}
			// Add the transition
			dfa[make_pair(dsit->second, *symit)]=dStates[mu];
		}
	}
	cout<< "The states are"<<endl;
	for(dsit=dStates.begin(); dsit!=dStates.end(); dsit++)
	{
		PrintVec(dsit->first);
		cout<<"\t"<<dsit->second<<endl;
	}

	cout<< "The set of final states are"<<endl;
	for(symit=final_states.begin(); symit!=final_states.end(); symit++)
	{
		cout<<*symit<<endl;
	}

	cout<<"The start state is: "<<start_state<<endl;

	cout<<"The dfa is"<<endl;
	// Print the dfa
	cout<<"--------------------------------------------------\n";
	cout<<"|\tFrom\t|\tSymbol\t|\tTo\t|\n";
	cout<<"--------------------------------------------------\n";
	for(dfait=dfa.begin(); dfait!=dfa.end(); dfait++)
	{
		cout<<"|\t"<<dfait->first.first<<"\t|\t"<<dfait->first.second<<"\t|\t"<<dfait->second<<"\t|"<<endl;
	}
	cout<<"--------------------------------------------------\n";
	return dfa;
}

// Function to simulate action of string on a dfa
bool is_valid_string(string str, map< pair<char, char>, char > dfa)
{
	char curr_state=start_state; // Start from the start state
	int i=0;
	for(;i<str.length();i++)
	{
		// First check if input is in alphabet
		if(symbols.count(str[i])==0)//Invalid input alphabet
			return false;
		cout<<"DFA moves from state "<<curr_state<<" to ";
		// Move to next state
		curr_state=dfa[make_pair(curr_state,str[i])];
		cout<<"state "<<curr_state<<" with input symbol "<<str[i]<<endl;
	}
	if(final_states.count(curr_state)!=0)// If current state is final state 
		return true;
	return false;
}
// Fucntion to print a vector
void PrintVec(vector<int> vec)
{
	int i=0;
	for(i=0;i<vec.size();i++)
	{
		if(i==vec.size()-1)
			cout<<vec[i];
		else
			cout<<vec[i]<<",";
	}
}