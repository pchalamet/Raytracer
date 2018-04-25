
#ifndef __LEXYY
#define __LEXYY


#include <stdio.h>

int yylex();

extern double vallex_double;
extern FILE *yyin;
extern int current_line;
#endif
