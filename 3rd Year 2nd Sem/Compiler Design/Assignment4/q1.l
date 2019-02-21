%{
	#include<stdio.h>
%}

%%

[A]*[B]* {printf("Correct\n");}

%%

int yywrap(void)
{
	return 1;
}

int main()
{
	yylex();
	return 0;
}