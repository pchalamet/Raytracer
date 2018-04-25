
%{

#include <string.h>

#include "csg.h"
#include "scene.h"
#include "objet.h"
#include "camera.h"
#include "lamp.h"
#include "vecteur.h"
#include "csg_tab.h"

double vallex_double;
int imbric_comment;
int current_line;


%}


chiffre [0-9]
lettre [a-zA-Z]
exp [eE]
sgn [+-]
quote '
delim [ \t\r]
newl [\n]

nombre {chiffre}+
entier {sng}?{nombre}
reel {sgn}?({nombre}([.]{exp}?{sgn}?{nombre})?)|([.]{exp}?{sgn}?{nombre})
blanc {delim}*


%x COMMENT


%%

<INITIAL>{blanc}
<INITIAL,COMMENT>{newl} { current_line++; }


"(" { return TK_PARO; }
")" { return TK_PARF; }

"<" { return TK_CHEVO; }
">" { return TK_CHEVF; }

"{" { return TK_ACCO; }
"}" { return TK_ACCF; }

"[" { return TK_CROCHO; }
"]" { return TK_CROCHF; }

"," { return TK_VIRG; }

"%%" { return TK_NEW_SECTION; }

intersection { return TK_INTERSECTION; }
union { return TK_UNION; }
negation { return TK_NEGATION; }

translation { return TK_TRANSLATION; }
rotation { return TK_ROTATION; }
scale { return TK_SCALE; }

quadric { return TK_QUADRIC; }
sphere { return TK_SPHERE; }
plane { return TK_PLANE; }

tile { return TK_TILE; }

camera { return TK_CAMERA; }
position { return TK_POSITION; }
spin { return TK_SPIN; }
look_at { return TK_LOOK_AT; }
width { return TK_WIDTH; }
height { return TK_HEIGHT; }
focal { return TK_FOCAL; }

lamp { return TK_LAMP; }
intensity { return TK_INTENSITY; }

ambiant { return TK_AMBIANT; }
diffuse { return TK_DIFFUSE; }
specular { return TK_SPECULAR; }
aspect { return TK_ASPECT; }
reflect { return TK_REFLECT; }

red { return TK_RED; }
green { return TK_GREEN; }
blue { return TK_BLUE; }


{reel} { vallex_double = atof(yytext);
         return TK_CONST; }



"/*" { imbric_comment=1;
       BEGIN(COMMENT); }
<COMMENT>"/*" { imbric_comment++; }
<COMMENT>"*/" { if (!(--imbric_comment))
                BEGIN(INITIAL); }
<COMMENT>.


"*/" { return TK_ERROR; }



<<EOF>> { if (imbric_comment)
            return TK_ERROR;
          else
            return YY_NULL; }


. { printf("token inconnu %s\n", yytext);
    return TK_ERROR; }

%%