#include<bits/stdc++.h>

using namespace std;

string remove_spaces(string regex);
string infix_to_postfix(string regex);
int prec(char c);

int main()
{
	string regex, post_regex;
	printf("Enter a regular expression\n");
	getline(cin, regex); //Regex contains the regular expression
	regex=remove_spaces(regex); // Remove spaces from regex if it contains any
	regex=regex+".#"; // Add the sentinel
	cout<<regex<<endl;
	// Convert the regular expression from infix to postfix
	post_regex=infix_to_postfix(regex);
	cout<<post_regex;
	//Construct syntax tree from the potfix expression of regex
	// Tree* node=construct_syntax_tree(post_regex);
	// Construct dfa from the tree
	// Print the dfa
	return 0;
}

// Function to remove spaces and + from regex
string remove_spaces(string regex)
{
	string nregex="";
	int i=0;
	for(;i<regex.length();i++)
	{
		if(regex[i]!=' ')
			nregex+=regex[i];
		else
		if(regex[i]=='+') // If + convert to *
		{
			nregex=regex[i-1]+regex[i-1]+'*';
		}
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
	st.push('$');
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
            while(st.top() != '$' && st.top() != '(') 
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
            while(st.top() != '$' && prec(regex[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                post_regex += c; 
            } 
            st.push(regex[i]); 
        } 
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != '$') 
    { 
        char c = st.top(); 
        st.pop(); 
        post_regex += c; 
    }
    return post_regex;
}