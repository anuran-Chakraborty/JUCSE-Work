%{
	#include<stdio.h>
%}

%%

"else" {printf("<else>");}
"if" {printf("<if>");}
"for" {printf("<for>");}
"int" {printf("<int>");}
"float" {printf("<float>");}
"void" {printf("<void>");}
"return" {printf("<return>");}

[+\-*/] {printf("<arith-op>");}
[<>] {printf("<relop>");}
[=] {printf("<assignop>");}
[/][/][^\n]* {}

[_a-zA-Z]+[0-9]*[_a-zA-Z0-9]* {printf("<ID>");}
[0-9]*[.]?[0-9]* {printf("<NUM>");}

[#][^\n]* {printf("<preprocessor>");}
["][^\n]*["] {printf("<String literal>");}


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