%{
    #include "y.tab.h"
    int yylex();
%}

%%
A   {return A;}
B   {return B;}
.   {return yytext[0];}
\n  {return yytext[0];}
%%

int yywrap(void)
{
	return 1;
}
