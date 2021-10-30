%option noyywrap

%{

	#include "includes/Parser/parser.hpp"
	int line_nr = 1;
	int col_nr = 1; 



%}

decimal_literal 		0|([1-9](_)?[0-9]+)*
binary_literal 			0(b|B)((_)?[0|1]+)+
ocatal_literal 			0(o|O)((_)?[0-7]+)+
heximal_literal 		0(x|X)((_)?[0-9a-fA-F]+)+

decimal_float_literal  	([0-9](_)?[0-9]+)*\.([0-9]((_)?[0-9]+)*)?

identifier 				[_a-zA-Z]([_a-zA-Z0-9])*


rune_escape_char 		\\(a|b|c|f|n|r|t|v|\'|\"|\\)
rune_hex_value 			\\(x)[0-9a-fA-F]{2}
rune_ocatal_value 		\\[0-7]{3}

rune_literal 			\'({rune_escape_char}|{rune_hex_value}|{rune_ocatal_value})
%%
"//".*  {}
[\t]  {}


bool    {return BOOL;}
int     {return INT;}
float32 {return float32;}
char    {return CHAR;}
string  {return STRING;}
rune    {return RUNE;}
byte    {return BYTE;}

{identifier} 	{
					auto s = new char(yyleng+1);
					strcpy(s, yytext);
					yylval.id = s;
					return ID;
				}

%%







/* Function called by (f)lex when EOF is read. If yywrap returns a
   true (non-zero) (f)lex will terminate and continue otherwise.*/
int yywrap(){
  return (1);
}
