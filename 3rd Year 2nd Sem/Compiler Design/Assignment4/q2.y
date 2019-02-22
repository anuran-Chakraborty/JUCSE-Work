%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<ctype.h>

	#define YYSTYPE int

	int yyerror(char* s);
	int yylex();
%}

%token ID
%left '+' '-'
%left '*' '/'

%%

S : S E '\n' {printf("Answer: %d \nEnter expression\n",$2);}
| S '\n' ;
| ;
| error '\n' { yyerror("Error: Enter the expression\n" );}
;

E : E '+' E {$$=$1+$3; };
| E '-' E {$$=$1-$3; };
| E '*' E {$$=$1*$3; };
| E '/' E {$$=$1/$3; };
| '(' E ')' {$$=$2; };
| ID
;

%%

int main()
{
    printf("Enter the expression:\n");
    yyparse();
}
int yyerror (char *s)
{
    printf("%s\n", s);
    return 0;
}