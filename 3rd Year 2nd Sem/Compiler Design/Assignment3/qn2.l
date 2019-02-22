%{
	#include<stdio.h>
%}

%%

"else" {printf("else\tkeyword\n");}
"if" {printf("if\tkeyword\n");}
"for" {printf("for\tkeyword\n");}
"int" {printf("int\tkeyword\n");}
"float" {printf("float\tkeyword\n");}
"void" {printf("void\tkeyword\n");}
"return" {printf("return\tkeyword\n");}
[ ] {}
[+\-*/] {printf("%s\tarith-op\n",yytext);}
[<>] {printf("%s\trelop\n",yytext);}
[=] {printf("%s\tassignop\n",yytext);}
[(){},;] {printf("%s\tspecial symbol\n",yytext);}

[/][/][^\n]* {}
[\n\t] {}

[_a-zA-Z]+[0-9]*[_a-zA-Z0-9]* {printf("%s\tID\n",yytext);}
[0-9]+[.]?[0-9]* {printf("%s\tNUM\n",yytext);}

[#][^\n]* {printf("%s\tpreprocessor\n",yytext);}
["][^\n]*["] {printf("%s\tString literal\n",yytext);}


%%

int yywrap(void)
{
	return 1;
}

int main(void)
{
	yylex();
	return 0;
}