%option noyywrap
%option header-file="includes/Lexer/lexer.hpp"
%{

	#include "Parser/parser.hpp"
	#include <string>
    #include <iostream>

    //rewrite and get debugging
    #define YY_USER_ACTION \
        yylloc.first_line = yylloc.last_line; \
        yylloc.first_column = yylloc.last_column; \
        for(int i = 0; yytext[i] != '\0'; i++) { \
            if(yytext[i] == '\n') { \
                yylloc.last_line++; \
                yylloc.last_column = 0; \
            } \
            else { \
                yylloc.last_column++; \
            } \
        }



	char *copyString(char *input);
	char *removeLowerLine(char *input);
	char *removeQuotes(char *input);

	long 	decimalToInteger(char *input);
	long 	binaryToInteger(char * input);
	long 	octalToInteger(char * input);
	long 	heximalToInteger(char * input);
	float 	decimalToFloat(char * input);

	char 	charTochar(char * input, int &length);

	char	charToCharLiteral(char * input);

    bool    semicollonPlac = false;
%}

decimal_literal 		0|([1-9]((_)?[0-9]+)*)
binary_literal 			0(b|B)((_)?[0|1]+)+
octal_literal 			0(o|O)?((_)?[0-7]+)+
heximal_literal 		0(x|X)((_)?[0-9a-fA-F]+)+

decimal_float_literal  	([0-9](_)?[0-9]+)*\.([0-9]((_)?[0-9]+)*)?




rune_escape_char 		\\(a|b|c|f|n|r|t|v|\'|\"|\\)
rune_hex_value 			\\(x)[0-9a-fA-F]{2}
rune_octal_value 		\\[0-7]{3}

rune_literal 			({rune_escape_char}|{rune_hex_value}|{rune_octal_value})


identifier 				[_a-zA-Z]([_a-zA-Z0-9])*
%%
"//".*  {}
[ \t\r]    {}
\n      {
            if(semicollonPlac){
                semicollonPlac = false;
                return ';';
            }
        }

bool    {semicollonPlac = true; return BOOL;}
int     {semicollonPlac = true; return INT;}
float32 {semicollonPlac = true; return FLOAT32;}
char    {semicollonPlac = true; return CHAR;}

rune    {semicollonPlac = true; return RUNE;}


if 		{semicollonPlac = false; return IF;}
else	{semicollonPlac = false; return ELSE;}
for     {semicollonPlac = false; return FOR;}
return  {semicollonPlac = true; return RETURN;}
var     {semicollonPlac = false; return VAR;}
func    {semicollonPlac = false; return FUNC;}

\&\&    {semicollonPlac = false; return AND; }
\|\|    {semicollonPlac = false; return OR; }
\!      {semicollonPlac = false; return NOT; }

\=\=    {semicollonPlac = false; return EQ;}
\!\=    {semicollonPlac = false; return NEQ;}


true    {semicollonPlac = true; yylval.booleanValue = true; return BOOLEAN_LITERAL; }
false   {semicollonPlac = true; yylval.booleanValue = false; return BOOLEAN_LITERAL; }


{binary_literal}		{semicollonPlac = true; yylval.integerValue = binaryToInteger(yytext); return INTEGER_LITERAL;}
{octal_literal}			{semicollonPlac = true; yylval.integerValue = octalToInteger(yytext); return INTEGER_LITERAL;}
{heximal_literal}		{semicollonPlac = true; yylval.integerValue = heximalToInteger(yytext); return INTEGER_LITERAL;}

{decimal_literal}		{semicollonPlac = true; yylval.integerValue = decimalToInteger(yytext); return INTEGER_LITERAL;}


{decimal_float_literal}	{semicollonPlac = true; yylval.floatValue = decimalToFloat(yytext); return FLOAT_LITERAL;}

\'{rune_literal}\'		{semicollonPlac = true; yylval.charValue = charToCharLiteral(yytext); return CHAR_LITERAL;}

{identifier} 		{semicollonPlac = true; yylval.identifierValue = copyString(yytext); return IDENTIFIER;}


.                       {
                            semicollonPlac = *yytext == '}' || *yytext == ']' || *yytext == ')' ; 
                                return *yytext; 
                        }
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

char charTochar(char *input, int &length){
    if(*input == '\\'){ //special case or other represenstation
        input = input + 1;      // go pass the first char /

        if(*input == 'x'){      //case of hex_value
            char result[3];
            result[0] = input[1];
            result[1] = input[2];
            result[2] = '\0';
            length = 4;
            return (char)std::strtol(result, nullptr, 16);
        }

        if(input[0] >='0' && input[0] <= '7'){
            char result[4];
            result[0] = input[0];
            result[1] = input[1];
            result[2] = input[2];
            result[3] = '\0';

            length = 4;
            return (char)std::strtol(result, nullptr, 8);
        }

        if(*input == 'a'){
            length = 2;
            return '\a';
        }else if(*input == 'b'){
            length = 2;
            return '\b';
        /* }else if(*input == 'c'){
            length = 2;
            return '\c'; */
        }else if(*input == 'f'){
            length = 2;
            return '\f';
        }else if(*input == 'n'){
            length = 2;
            return '\n';
        } else if(*input == 'r'){
            length = 2;
            return  '\r';
        } else if(*input == 't'){
            length = 2;
            return '\t';
        }else if(*input == 'v'){
            length = 2;
            return '\v';
        }else if(*input == '\''){
            length = 2;
            return '\'';
        }else if(*input == '\"'){
            length = 2;
            return '\"';
        }else if(*input == '\\'){
            length = 2;
            return '\\';
        }

    }else{
        length = 1;
        return *input;
    }
    length = 1;
    return *input;
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
	if(formated[1]!='o' && formated[1]!='O'){		//llok if o or O is placed
		formated = formated +1;
	}else{
		formated = formated + 2; //remove 0o or 0O 
	}
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
	auto noQuotes = removeQuotes(input);
    int length = 0;
	auto result = charTochar(noQuotes, length);
	delete noQuotes;
	return result;
}
//TODO: start making the stupid tree
