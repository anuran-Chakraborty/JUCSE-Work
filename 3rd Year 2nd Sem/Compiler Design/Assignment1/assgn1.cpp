#include<bits/stdc++.h>

using namespace std;

set<string> loadTokenTypes(string filename);
void tokenize(string line);
void printTokenAndTypes();
void readFileAndTokenize(string filename);
bool isConstant(string word);

vector<pair<string, string> > tokens_list;
vector<pair<int, int> > row_col_list;
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

// Check if a string is a constant
bool isConstant(string word)
{
	int countdec=0; // Number of decimal points
	bool cons=true;
	int i;

	for(i=0;i<word.length();i++)
	{
		if(word[i]=='.')
			countdec++;
		else
		if(word[i]<'0' || word[i]>'9')
		{
			cons=false;
			break;
		}
	}
	return ((countdec<=1) && cons);
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
	while(!fio.eof())
	{
		getline(fio, line);
		// if(fio.eof())
		// 	break;
		// Add to the set
		// cout<<line<<endl;
		tokens.insert(line);
	}
	return tokens;
}

// Function to tokenize every line
void tokenize(string line, int rownum)
{
	int i, colnum=1;	// colnum stores the current column number
	string word="";
	bool isLiteral=false;
	bool isCharConst=false;
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
				// Check if word is a constant
				else
				if(isConstant(word))
					// Insert it as constant
					tokens_list.push_back(make_pair(word, "constant"));
				else
				{
					// Insert it
					// cout<<"Inserting into identifier"<<endl;
					tokens_list.push_back(make_pair(word, "identifier"));
				}
				row_col_list.push_back(make_pair(rownum, colnum-word.length()));
				word="";
			}
		}
		else
		if(punc.count(character)!=0) //Means it is a punctuation
		{
			// Insert the previously acquired word if it is not null
			if(!isLiteral && character=="\"")	// Case for beginning of literal
			{
				// Start the literal
				tokens_list.push_back(make_pair(character, "punctuation"));
				row_col_list.push_back(make_pair(rownum, colnum));
				isLiteral=true;
			}
			else
			if(!isCharConst && character=="\'")
			{
				tokens_list.push_back(make_pair(character, "punctuation"));
				row_col_list.push_back(make_pair(rownum, colnum));
				isCharConst=true;
			}
			if(word!="")
			{
				// Check if word is in any of the predefined symbols
				if(keywords.count(word)!=0) // Means it is a keyword
					// Insert it as keyword
					tokens_list.push_back(make_pair(word, "keyword"));
				// Check if word is a literal
				else
				if(isLiteral && character=="\"")
				{
					// Then it is end of literal
					isLiteral=false;
					// Insert it as literal
					tokens_list.push_back(make_pair(word, "literal"));
				}
				else
				if(isCharConst && character=="\'")
				{
					// Then it is end of literal
					isCharConst=false;
					// Insert it as literal
					tokens_list.push_back(make_pair(word, "character constant"));
				}
				// Check if word is a constant
				else
				if(isConstant(word))
					// Insert it as constant
					tokens_list.push_back(make_pair(word, "constant"));
				else
					// Insert it as identifier
					tokens_list.push_back(make_pair(word, "identifier"));
				row_col_list.push_back(make_pair(rownum, colnum-word.length()));
				word="";
			}
			// If punctuation is within the literal then make sure it is not inserted
			if(!isLiteral && !isCharConst)
			{
				// Also insert the punctuation
				tokens_list.push_back(make_pair(character, "punctuation"));
				row_col_list.push_back(make_pair(rownum, colnum));
			}

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
				// Check if word is a constant
				else
				if(isConstant(word))
					// Insert it as constant
					tokens_list.push_back(make_pair(word, "constant"));
				else
					// Insert it as identifier
					tokens_list.push_back(make_pair(word, "identifier"));
				row_col_list.push_back(make_pair(rownum, colnum-word.length()));
				word="";
			}
			string tempchar=character+line[i+1];
			// Check case for ==
			if(operators.count(tempchar)!=0) // If it is a two character operator
			{
				character+=line[i+1];
				colnum++;
				i++;
			}
			// Also insert the punctuation
			tokens_list.push_back(make_pair(character, "operator"));
			row_col_list.push_back(make_pair(rownum, colnum-character.length()+1));
		}
		else
			word+=line[i];
		colnum++;
		if(line[i]=='\t')
			colnum+=3;
	}
}

// Function to read the file and tokenize it
void readFileAndTokenize(string filename)
{
	const char *file = filename.c_str();
	// Open and read file
	fstream fio;
	string line;
	int i=1;
	fio.open(file, ios::in);
	// Read the file
	while(!fio.eof())
	{
		getline(fio, line);
		tokenize(line,i);
		i++;
	}
}
// Function to print the tokens and types
void printTokenAndTypes()
{
	cout<<"Printing tokens"<<endl;
	int i;
	for(i=0;i<tokens_list.size();i++)
	{
		cout<<"Row: "<<row_col_list[i].first<<", Col: "<<row_col_list[i].second<<"\t\t"<<tokens_list[i].first<<" : "<<tokens_list[i].second<<endl;
	}
}