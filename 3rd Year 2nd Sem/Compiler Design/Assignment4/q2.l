%{
	#include "y.tab.h"
%}

%%

[0-9]+[.]?[0-9]+ {yylval=atoi(yytest); return ID;}
\n {return yytext[0];}

%%

int yywrap(void)
{
	return 1;
}