#include<bits/stdc++.h>

using namespace std;

set<string> loadTokenTypes(string filename);
void tokenize(string line);
void printTokenAndTypes();
void readFileAndTokenize(string filename);

vector<pair<string, string> > tokens_list;
set<string> keywords;	// Set of all keywords
set<string> punc;		// Set of all punctuations
set<string> operators;	// Set of all operators

int main(int argc, char const *argv[])
{
	if(argc<=1)
	{
		cout<<"Error: No input files"<<endl;
		return 0;
	}
	// Load the keywords
	keywords=loadTokenTypes("keywords.txt");
	// Load the punctuations
	punc=loadTokenTypes("punctuations.txt");
	// Load the operators
	operators=loadTokenTypes("operators.txt");

	// Read the file and tokenize
	readFileAndTokenize(argv[1]);

	// Print the tokens
	printTokenAndTypes();


	return 0;
}

// Function to read the keywords, etc. form a file and return a set
set<string> loadTokenTypes(string filename)
{
	const char *file = filename.c_str();

	set<string> tokens;
	cout<<"Reading file "<<filename<<endl;
	// Open and read file
	fstream fio;
	string line;

	fio.open(file,ios::in);
	if(!fio)
	{
		cout<<"Error in opening file"<<endl;
		exit(0);
	}
	// Read the file
	while(fio)
	{
		getline(fio, line);
		if(line=="EOF")
			break;
		// Add to the set
		// cout<<line<<endl;
		tokens.insert(line);
	}
	return tokens;
}

// Function to tokenize every line
void tokenize(string line)
{
	int i;
	string word="";
	for(i=0;i<line.length();i++)
	{
		string character(1,line[i]);
		// cout<<word<<endl;
		if(line[i]==' ' || line[i]=='\t')
		{
			if(word!="")
			{
				// Check if word is in any of the predefined symbols
				if(keywords.count(word)!=0) // Means it is a keyword
				{
					// Insert it
					// cout<<"Inserting into keyword"<<endl;
					tokens_list.push_back(make_pair(word, "keyword"));
				}
				else
				{
					// Insert it
					// cout<<"Inserting into identifier"<<endl;
					tokens_list.push_back(make_pair(word, "identifier"));
				}
				word="";
			}
		}
		else
		if(punc.count(character)!=0) //Means it is a punctuation
		{
			// cout<<"Punctuation encountered"<<endl;
			// Insert the previously acquired word if it is not null
			if(word!="")
			{
				// Check if word is in any of the predefined symbols
				if(keywords.count(word)!=0) // Means it is a keyword
					// Insert it as keyword
					tokens_list.push_back(make_pair(word, "keyword"));
				else
					// Insert it as identifier
					tokens_list.push_back(make_pair(word, "identifier"));
				word="";
			}
			// Also insert the punctuation
			tokens_list.push_back(make_pair(character, "punctuation"));

		}
		else
		if(operators.count(character)!=0) // means if it is an operator
		{
			// cout<<"Operator encountered"<<endl;
			// Insert the previously acquired word if it is not null
			if(word!="")
			{
				// Check if word is in any of the predefined symbols
				if(keywords.count(word)!=0) // Means it is a keyword
					// Insert it as keyword
					tokens_list.push_back(make_pair(word, "keyword"));
				else
					// Insert it as identifier
					tokens_list.push_back(make_pair(word, "identifier"));
				word="";
			}
			// Also insert the punctuation
			tokens_list.push_back(make_pair(character, "operator"));
		}
		else
			word+=line[i];
	}
}

// Function to read the file and tokenize it
void readFileAndTokenize(string filename)
{
	const char *file = filename.c_str();
	// Open and read file
	fstream fio;
	string line;

	fio.open(file, ios::in);
	// Read the file
	while(fio)
	{
		getline(fio, line);
		if(line=="EOF")
			break;
		// Add to the set
		// cout<<line<<endl;
		tokenize(line);
	}
}
// Function to print the tokens and types
void printTokenAndTypes()
{
	cout<<"Printing tokens"<<endl;
	int i;
	for(i=0;i<tokens_list.size();i++)
	{
		cout<<tokens_list[i].first<<" : "<<tokens_list[i].second<<endl;
	}
}