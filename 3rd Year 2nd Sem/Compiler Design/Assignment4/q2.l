%{
	#include "y.tab.h"
%}

%%
[ ]
[0-9]+ {yylval=atoi(yytext); return ID;}
\n|. {return yytext[0];}

%%

int yywrap(void)
{
	return 1;
}