%option noyywrap
%option header-file="includes/Lexer/lexer.hpp"
%{

	#include "Parser/parser.hpp"
	#include <string>
	int line_nr = 1;
	int col_nr = 1; 

	char *copyString(char *input);
	char *removeLowerLine(char *input);
	char *removeQuotes(char *input);

	long 	decimalToInteger(char *input);
	long 	binaryToInteger(char * input);
	long 	octalToInteger(char * input);
	long 	heximalToInteger(char * input);
	float 	decimalToFloat(char * input);

	char	charToCharLiteral(char * input);
%}

decimal_literal 		0|([1-9](_)?[0-9]+)*
binary_literal 			0(b|B)((_)?[0|1]+)+
octal_literal 			0(o|O)?((_)?[0-7]+)+
heximal_literal 		0(x|X)((_)?[0-9a-fA-F]+)+

decimal_float_literal  	([0-9](_)?[0-9]+)*\.([0-9]((_)?[0-9]+)*)?

identifier 				[_a-zA-Z]([_a-zA-Z0-9])*


rune_escape_char 		\\(a|b|c|f|n|r|t|v|\'|\"|\\)
rune_hex_value 			\\(x)[0-9a-fA-F]{2}
rune_octal_value 		\\[0-7]{3}

rune_literal 			({rune_escape_char}|{rune_hex_value}|{rune_octal_value})



%%
"//".*  {}
[\t]  {}


bool    {return BOOL;}
int     {return INT;}
float32 {return FLOAT32;}
char    {return CHAR;}
string  {return STRING;}
rune    {return RUNE;}
byte    {return BYTE;}
if 		{return IF;}
else	{return ELSE;}

{identifier} 		{yylval.identifierValue = copyString(yytext); return IDENTIFIER;}


{decimal_literal}		{yylval.integerValue = decimalToInteger(yytext); return INTEGER_LITERAL;}
{binary_literal}		{yylval.integerValue = binaryToInteger(yytext); return INTEGER_LITERAL;}
{octal_literal}			{yylval.integerValue = octalToInteger(yytext); return INTEGER_LITERAL;}
{heximal_literal}		{yylval.integerValue = heximalToInteger(yytext); return INTEGER_LITERAL;}

{decimal_float_literal}	{yylval.floatValue = decimalToFloat(yytext); return FLOAT_LITERAL;}

\'{rune_literal}\'		{yylval.charValue = }
%%



/* Function called by (f)lex when EOF is read. If yywrap returns a
   true (non-zero) (f)lex will terminate and continue otherwise.*/

char *copyString(char *input){
	auto s = new char[strlen(input)+1];
	strcpy(s, input);
	return s;
}

char *removeLowerLine(char *input){
    auto result = new char[strlen(input)+1];
    size_t j = 0;

    for(size_t i=0; i<strlen(input); i++){
        if(input[i] !='_') {
            result[j] = input[i];
            j++;
        }
    }
    result[j] = '\0';
    return result;
}

char *removeQuotes(char *input){
	auto result = copyString(input+1); 	//remove the first "
	result[strlen(result)-1] = '\0';	//remove the second "
	return result;
}

long decimalToInteger(char *input){
	auto formated = removeLowerLine(input);
	return std::stol(formated, nullptr, 10);
}

long binaryToInteger(char *input){
	auto formated = removeLowerLine(input);
	formated = formated + 2; //remove 0b or 0B
	return std::stol(formated, nullptr, 2);
}

long octalToInteger(char *input){
	auto formated = removeLowerLine(input);
	formated = formated + 2; //remove 0o or 0O //llok if o or O is placed
	return std::stol(formated, nullptr, 8);
}

long heximalToInteger(char *input){
	auto formated = removeLowerLine(input);
	formated = formated + 2; //remove 0x or 0X
	return std::stol(formated, nullptr, 16);
}

float decimalToFloat(char *input){
	auto formated = removeLowerLine(input);
	return std::stof(formated);
}

char charToCharLiteral(char *input){

}
//TODO: start making the stupid tree