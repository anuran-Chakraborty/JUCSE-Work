%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token A B
%%
S1 : S '\n' {return 0;}
S: C D;
C: A C|;
D: B D|;
%%

int main(void)
{
    printf ("Grammar to accept strings of the form A*B*\n");
    printf("Enter the string to parse\n");
    yyparse();
    printf("Valid String\n");
}

void yyerror(char *s) 
{
	printf("Parse error: %s\n",s);
	exit(-1);
}