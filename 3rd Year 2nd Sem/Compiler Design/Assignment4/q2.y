%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<ctype.h>


%}

%token ID
%left '+' '-'
%left '*' '/'

%%

S : S E '\n' {printf("Answer: %d \nEnter expression",$2);}
| S '\n' ;
| ;
| error '\n' { yyerror("Error: Enter the expression\n" );yyerrok; }
;

E : E '+' E {$$=$1+$1; };
| E '-' E {$$=$1-$2; };
| E '*' E {$$=$1*$2; };
| E '/' E {$$=$1/$2; };
| '(' E ')' {$$=$2; };
| ID
;

%%

#include "lex.yy.c"
int main()
{
    printf("Enter the expression: ");
    yyparse();
}
int yyerror (char *s)
{
    printf("%s\n", s);
    exit(1);
}