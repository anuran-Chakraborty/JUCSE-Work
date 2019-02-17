%{
	#include<stdio.h>
	int linecount=0, wcount=0, charcount=0, integers=0, decimals=0;
%}
%%

\n { linecount++;}
[\t' '] { wcount++;}
[0-9]+ {integers++;}
([0-9]+[.])[0-9]+ {decimals++;}
. { charcount++;}


%%

int main()
{
	yylex();
	printf("There are %d lines in the input\n",++linecount);
	printf("There are %d words in the input\n",++wcount);
	printf("There are %d characters in the input\n",charcount);
	printf("There are %d integers in the input\n",integers);
	printf("There are %d floating in the input\n",decimals);
	return 0;
}