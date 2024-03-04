/*

Name: Md. Waliul Islam Rayhan
ID: B190305034

*/

%{
	#include<stdio.h>
	int keyword = 0, 
	comment = 0, 
	Arithmatic_op = 0, 
	Relational_op = 0,
	Assignment_op=0,
	Unary_op=0, 
	Logical_op=0,
	preprocessor =0,
	func =0,
	number=0,
	id=0; 
	
%}
%%
auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|short|float|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while     {keyword++; printf("\"%s\" is a keyword\n\n",yytext);}


"#".*"\n" {preprocessor++; printf("\"%s\" is a preprocessor directive\n\n",yytext);}


"/*".*("\n")*.*"*/"   {comment++;printf("\"%s\" is a multi line comment\n\n",yytext);}

[ \t]*"//".*"\n"  {comment++;printf("\"%s\" is a single line comment\n\n",yytext);}




"+"|"-"|"*"|"/"|"+="|"-="|"*="|"/="|"%" {Arithmatic_op++;printf("\"%s\" is a arithmatic operator\n\n",yytext);}



"++"|"--" {Unary_op++;printf("\"%s\" is unary operator\n\n",yytext);}



"<"|">"|"=="|">="|"<="|"!=" {Relational_op++;printf("\"%s\" is a relational operator\n\n",yytext);}



([^><]"=") {Assignment_op++;printf("\"%s\" is a assignment operator\n\n",yytext);}



"||"|"&&"|"!" {Logical_op++;printf("\"%s\" is a logical operator\n\n",yytext);}

"main(".*")"|"printf(".*")"|"scanf(".*")"  {func++; printf("\"%s\" is a function\n\n",yytext);}

[+-]?[0-9]+[.]?[0-9]* {number++; printf("\"%s\" is a number\n\n",yytext);}

[a-zA-Z_][a-zA-Z0-9_]* {	id++; 
				printf("\"%s\" is identifier\n\n",yytext);
			}


 
.|"\n" { ;} 

%%


int main(){

	yyin = fopen("SampleInput.c","r");
	yylex();
	printf("The no. of Preprocessors is: %d\n",preprocessor);
	printf("The no. of Keywords is: %d\n",keyword);
	printf("The no. of comments is: %d\n",comment);
        printf("The no. of Arithmatic operator is: %d\n",Arithmatic_op);
 	printf("The no. of Unary operator is: %d\n",Unary_op);
	printf("The no. of Relational operator is: %d\n",Relational_op);
	printf("The no. of Assignment operator is: %d\n",Assignment_op);
	printf("The no. of Logical operator is: %d\n",Logical_op);
	printf("The no. of Function is: %d\n",func);
	printf("The no. of Numbers is: %d\n",number);
	printf("The no. of Identifiers is: %d\n",id);
	return 0;
}
int yywrap()
{ return 1;
}



