
/*  A Bison parser, made from scan.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TK_ERROR	258
#define	TK_PARO	259
#define	TK_PARF	260
#define	TK_CHEVO	261
#define	TK_CHEVF	262
#define	TK_VIRG	263
#define	TK_ACCO	264
#define	TK_ACCF	265
#define	TK_CROCHO	266
#define	TK_CROCHF	267
#define	TK_NEW_SECTION	268
#define	TK_CONST	269
#define	TK_INTERSECTION	270
#define	TK_UNION	271
#define	TK_NEGATION	272
#define	TK_TRANSLATION	273
#define	TK_ROTATION	274
#define	TK_SCALE	275
#define	TK_QUADRIC	276
#define	TK_SPHERE	277
#define	TK_PLANE	278
#define	TK_TILE	279
#define	TK_CAMERA	280
#define	TK_POSITION	281
#define	TK_LOOK_AT	282
#define	TK_SPIN	283
#define	TK_WIDTH	284
#define	TK_HEIGHT	285
#define	TK_FOCAL	286
#define	TK_LAMP	287
#define	TK_INTENSITY	288
#define	TK_AMBIANT	289
#define	TK_DIFFUSE	290
#define	TK_SPECULAR	291
#define	TK_REFLECT	292
#define	TK_ASPECT	293
#define	TK_RED	294
#define	TK_GREEN	295
#define	TK_BLUE	296

#line 2 "scan.y"



#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

#include "csg.h"
#include "scene.h"
#include "camera.h"
#include "lamp.h"
#include "objet.h"
#include "vecteur.h"
#include "property.h"
#include "lexyy.h"

/* prototypes des fonctions */

void yyerror(char *);
int yywrap(void);



t_camera *h_camera;
t_lamp *h_lamp;
t_properties *h_property;
int h_kind_composante;
double s_ambiant = 0.2;
t_csg *h_csg,*temp_csg,*org_csg;




#line 38 "scan.y"
typedef union {
	t_csg *csg;
	t_scene *scene;
	t_objet *objet;
	t_camera *camera;
	t_lamp *lamp;
	t_vecteur vecteur;
	t_composante composante;
	double val;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		140
#define	YYFLAG		-32768
#define	YYNTBASE	42

#define YYTRANSLATE(x) ((unsigned)(x) <= 296 ? yytranslate[x] : 89)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     6,     8,     9,    15,    16,    19,    22,    25,    28,
    31,    34,    37,    40,    43,    46,    49,    52,    53,    56,
    57,    63,    64,    67,    70,    73,    76,    77,    80,    82,
    84,    86,    88,    90,    92,    98,   104,   109,   110,   116,
   117,   120,   123,   124,   130,   131,   134,   137,   139,   142,
   144,   146,   148,   151,   154,   157,   159,   161,   163,   165,
   167,   170,   173,   176,   179,   182,   183,   184,   185,   196,
   197,   198,   199
};

static const short yyrhs[] = {    43,
    13,    52,    13,    58,     0,     1,     0,     0,    25,     9,
    44,    45,    10,     0,     0,    46,    45,     0,    47,    45,
     0,    48,    45,     0,    49,    45,     0,    50,    45,     0,
    51,    45,     0,    26,    81,     0,    27,    81,     0,    28,
    14,     0,    29,    14,     0,    30,    14,     0,    31,    14,
     0,     0,    53,    52,     0,     0,    32,     9,    54,    55,
    10,     0,     0,    56,    55,     0,    57,    55,     0,    26,
    81,     0,    33,    14,     0,     0,    59,    58,     0,    60,
     0,    61,     0,    62,     0,    63,     0,    64,     0,    67,
     0,    15,     9,    60,    60,    10,     0,    16,     9,    60,
    60,    10,     0,    17,     9,    60,    10,     0,     0,    22,
     9,    65,    66,    10,     0,     0,    71,    66,     0,    75,
    66,     0,     0,    23,     9,    68,    69,    10,     0,     0,
    71,    69,     0,    75,    69,     0,    70,     0,    24,    14,
     0,    72,     0,    73,     0,    74,     0,    18,    81,     0,
    19,    81,     0,    20,    81,     0,    76,     0,    77,     0,
    78,     0,    79,     0,    80,     0,    34,    85,     0,    35,
    85,     0,    37,    85,     0,    36,    85,     0,    38,    14,
     0,     0,     0,     0,     6,    14,    82,     8,    14,    83,
     8,    14,    84,     7,     0,     0,     0,     0,    11,    14,
    86,     8,    14,    87,     8,    14,    88,    12,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   124,   135,   144,   157,   162,   163,   164,   165,   166,   167,
   168,   172,   176,   180,   184,   188,   192,   201,   203,   209,
   216,   220,   221,   222,   225,   229,   239,   241,   246,   252,
   253,   254,   255,   256,   260,   271,   282,   293,   311,   314,
   315,   316,   321,   341,   344,   345,   346,   347,   351,   358,
   359,   360,   366,   375,   384,   394,   395,   396,   397,   398,
   403,   408,   414,   419,   424,   429,   430,   431,   433,   439,
   440,   441,   443
};

static const char * const yytname[] = {   "$","error","$undefined.","TK_ERROR",
"TK_PARO","TK_PARF","TK_CHEVO","TK_CHEVF","TK_VIRG","TK_ACCO","TK_ACCF","TK_CROCHO",
"TK_CROCHF","TK_NEW_SECTION","TK_CONST","TK_INTERSECTION","TK_UNION","TK_NEGATION",
"TK_TRANSLATION","TK_ROTATION","TK_SCALE","TK_QUADRIC","TK_SPHERE","TK_PLANE",
"TK_TILE","TK_CAMERA","TK_POSITION","TK_LOOK_AT","TK_SPIN","TK_WIDTH","TK_HEIGHT",
"TK_FOCAL","TK_LAMP","TK_INTENSITY","TK_AMBIANT","TK_DIFFUSE","TK_SPECULAR",
"TK_REFLECT","TK_ASPECT","TK_RED","TK_GREEN","TK_BLUE","main","camera","@1",
"params_camera","camera_position","camera_look_at","camera_spin","camera_width",
"camera_height","camera_focal","liste_lampes","lamp","@2","params_lamp","lamp_position",
"lamp_intensity","liste_objets","objet","csg","csg_intersection","csg_union",
"csg_negation","csg_sphere","@3","params_sphere","csg_plane","@4","params_plane",
"plane_tile","transformations","transf_translation","transf_rotation","transf_scale",
"properties","ambiant","diffusion","reflection","speculaire","aspect","vecteur",
"@5","@6","@7","compo","@8","@9","@10",""
};
#endif

static const short yyr1[] = {     0,
    42,    42,    44,    43,    45,    45,    45,    45,    45,    45,
    45,    46,    47,    48,    49,    50,    51,    52,    52,    54,
    53,    55,    55,    55,    56,    57,    58,    58,    59,    60,
    60,    60,    60,    60,    61,    62,    63,    65,    64,    66,
    66,    66,    68,    67,    69,    69,    69,    69,    70,    71,
    71,    71,    72,    73,    74,    75,    75,    75,    75,    75,
    76,    77,    78,    79,    80,    82,    83,    84,    81,    86,
    87,    88,    85
};

static const short yyr2[] = {     0,
     5,     1,     0,     5,     0,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     0,     2,     0,
     5,     0,     2,     2,     2,     2,     0,     2,     1,     1,
     1,     1,     1,     1,     5,     5,     4,     0,     5,     0,
     2,     2,     0,     5,     0,     2,     2,     1,     2,     1,
     1,     1,     2,     2,     2,     1,     1,     1,     1,     1,
     2,     2,     2,     2,     2,     0,     0,     0,    10,     0,
     0,     0,    10
};

static const short yydefact[] = {     0,
     2,     0,     0,     3,    18,     5,     0,     0,    18,     0,
     0,     0,     0,     0,     0,     0,     5,     5,     5,     5,
     5,     5,    20,    27,    19,     0,    12,    13,    14,    15,
    16,    17,     4,     6,     7,     8,     9,    10,    11,    22,
     0,     0,     0,     0,     0,     1,    27,    29,    30,    31,
    32,    33,    34,    66,     0,     0,     0,    22,    22,     0,
     0,     0,    38,    43,    28,     0,    25,    26,    21,    23,
    24,     0,     0,     0,    40,    45,     0,     0,     0,    37,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
    50,    51,    52,    40,    56,    57,    58,    59,    60,     0,
     0,    48,    45,    45,    67,    35,    36,    53,    54,    55,
     0,    61,    62,    64,    63,    65,    39,    41,    42,    49,
    44,    46,    47,     0,    70,     0,     0,    68,     0,     0,
    71,    69,     0,     0,    72,     0,    73,     0,     0,     0
};

static const short yydefgoto[] = {   138,
     3,     6,    16,    17,    18,    19,    20,    21,    22,     8,
     9,    40,    57,    58,    59,    46,    47,    48,    49,    50,
    51,    52,    75,    89,    53,    76,   101,   102,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,    27,    66,
   124,   130,   112,   127,   133,   136
};

static const short yypact[] = {     1,
-32768,    10,    12,-32768,    -5,    25,    37,    35,    -5,    59,
    59,    52,    53,    54,    55,    63,    25,    25,    25,    25,
    25,    25,-32768,    -8,-32768,    60,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    14,
    66,    67,    68,    69,    70,-32768,    -8,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    59,    71,    72,    14,    14,    -8,
    -8,    -8,-32768,-32768,-32768,    73,-32768,-32768,-32768,-32768,
-32768,    -8,    -8,    74,    -2,   -14,    75,    76,    77,-32768,
    59,    59,    59,    79,    79,    79,    79,    78,    81,    -2,
-32768,-32768,-32768,    -2,-32768,-32768,-32768,-32768,-32768,    80,
    83,-32768,   -14,   -14,-32768,-32768,-32768,-32768,-32768,-32768,
    82,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    87,-32768,    84,    89,-32768,    85,    93,
-32768,-32768,    94,    90,-32768,    91,-32768,    88,   101,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,    40,-32768,-32768,-32768,-32768,-32768,-32768,    96,
-32768,-32768,   -16,-32768,-32768,    33,-32768,   -23,-32768,-32768,
-32768,-32768,-32768,   -49,-32768,-32768,   -40,-32768,   -75,-32768,
-32768,-32768,   -73,-32768,-32768,-32768,-32768,-32768,   -11,-32768,
-32768,-32768,   -74,-32768,-32768,-32768
};


#define	YYLAST		105


static const short yytable[] = {    28,
   103,     1,   104,    81,    82,    83,    41,    42,    43,   100,
   113,   114,   115,    44,    45,    81,    82,    83,     4,    84,
    85,    86,    87,    88,     5,     2,     7,   103,   103,   104,
   104,    84,    85,    86,    87,    88,    72,    73,    74,    55,
   118,    70,    71,    67,   119,    23,    56,    24,    78,    79,
    10,    11,    12,    13,    14,    15,    34,    35,    36,    37,
    38,    39,   122,   123,    26,    29,    30,    31,    32,   108,
   109,   110,    33,    54,    60,    61,    62,    63,    64,    65,
    77,    69,     0,    80,    68,   106,   107,   139,   105,   111,
   117,   116,   121,   120,   126,   125,   129,   128,   131,   132,
   140,   134,   137,   135,    25
};

static const short yycheck[] = {    11,
    76,     1,    76,    18,    19,    20,    15,    16,    17,    24,
    85,    86,    87,    22,    23,    18,    19,    20,     9,    34,
    35,    36,    37,    38,    13,    25,    32,   103,   104,   103,
   104,    34,    35,    36,    37,    38,    60,    61,    62,    26,
    90,    58,    59,    55,    94,     9,    33,    13,    72,    73,
    26,    27,    28,    29,    30,    31,    17,    18,    19,    20,
    21,    22,   103,   104,     6,    14,    14,    14,    14,    81,
    82,    83,    10,    14,     9,     9,     9,     9,     9,    47,
     8,    10,    -1,    10,    14,    10,    10,     0,    14,    11,
    10,    14,    10,    14,     8,    14,     8,    14,    14,     7,
     0,     8,    12,    14,     9
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 129 "scan.y"
{ yyval.scene = (t_scene *)alloca(sizeof(t_scene));
         yyval.scene->camera = yyvsp[-4].camera;
         yyval.scene->lamps = yyvsp[-2].lamp;
	       yyval.scene->objets = yyvsp[0].objet;
	 yyval.scene->ambiant = s_ambiant;
	 return (int)yyval.scene; ;
    break;}
case 2:
#line 135 "scan.y"
{ return (int)NULL; ;
    break;}
case 3:
#line 145 "scan.y"
{ h_camera = (t_camera *)alloca(sizeof(t_camera));
	   h_camera->pos.x = 0.0;
	   h_camera->pos.y = 0.0;
	   h_camera->pos.z = -20.0;
	   h_camera->dir.x = 0.0;
	   h_camera->dir.y = 0.0;
	   h_camera->dir.z = 1.0;
	   h_camera->spin = 0.0;
	   h_camera->width = 64.0;
	   h_camera->height = 40.0;
	   h_camera->focal = 10.0; ;
    break;}
case 4:
#line 158 "scan.y"
{ yyval.camera = h_camera; ;
    break;}
case 12:
#line 173 "scan.y"
{ h_camera->pos = yyvsp[0].vecteur; ;
    break;}
case 13:
#line 177 "scan.y"
{ h_camera->dir = yyvsp[0].vecteur; ;
    break;}
case 14:
#line 181 "scan.y"
{ h_camera->spin = vallex_double; ;
    break;}
case 15:
#line 185 "scan.y"
{ h_camera->width = vallex_double; ;
    break;}
case 16:
#line 189 "scan.y"
{ h_camera->height = vallex_double; ;
    break;}
case 17:
#line 193 "scan.y"
{ h_camera->focal = vallex_double; ;
    break;}
case 18:
#line 202 "scan.y"
{ yyval.lamp =NULL; ;
    break;}
case 19:
#line 204 "scan.y"
{ yyval.lamp = yyvsp[-1].lamp;
		 yyval.lamp->next = yyvsp[0].lamp; ;
    break;}
case 20:
#line 210 "scan.y"
{ h_lamp = (t_lamp *)alloca(sizeof(t_lamp));
	 h_lamp->pos.x = 0.0;
	 h_lamp->pos.y = 0.0;
	 h_lamp->pos.z = 0.0;
	 h_lamp->intensity = 1.0; ;
    break;}
case 21:
#line 217 "scan.y"
{ yyval.lamp = h_lamp; ;
    break;}
case 25:
#line 226 "scan.y"
{ h_lamp->pos = yyvsp[0].vecteur; ;
    break;}
case 26:
#line 230 "scan.y"
{ h_lamp->intensity = vallex_double; ;
    break;}
case 27:
#line 240 "scan.y"
{ yyval.objet = NULL; ;
    break;}
case 28:
#line 242 "scan.y"
{ yyval.objet = yyvsp[-1].objet;
		 yyval.objet->next = yyvsp[0].objet; ;
    break;}
case 29:
#line 247 "scan.y"
{ yyval.objet = (t_objet *)alloca(sizeof(t_objet));
	  yyval.objet->csg = h_csg; ;
    break;}
case 30:
#line 252 "scan.y"
{ yyval.csg = h_csg; ;
    break;}
case 31:
#line 253 "scan.y"
{ yyval.csg = h_csg; ;
    break;}
case 32:
#line 254 "scan.y"
{ yyval.csg = h_csg; ;
    break;}
case 33:
#line 255 "scan.y"
{ yyval.csg = h_csg; ;
    break;}
case 34:
#line 256 "scan.y"
{ yyval.csg = h_csg; ;
    break;}
case 35:
#line 264 "scan.y"
{ h_csg = (t_csg *)alloca(sizeof(t_csg));
		     h_csg->type = CSG_INTERSECTION;
		     h_csg->u_objet.deux_fils.fils_g = yyvsp[-2].csg;
		     h_csg->u_objet.deux_fils.fils_d = yyvsp[-1].csg; ;
    break;}
case 36:
#line 275 "scan.y"
{ h_csg = (t_csg *)alloca(sizeof(t_csg));
	      h_csg->type = CSG_UNION;
	      h_csg->u_objet.deux_fils.fils_g = yyvsp[-2].csg;
	      h_csg->u_objet.deux_fils.fils_d = yyvsp[-1].csg; ;
    break;}
case 37:
#line 285 "scan.y"
{ h_csg = (t_csg *)alloca(sizeof(t_csg));
		 h_csg->type = CSG_NEGATION;
		 h_csg->u_objet.un_fils.fils = yyvsp[-1].csg; ;
    break;}
case 38:
#line 294 "scan.y"
{ h_csg = (t_csg *)alloca(sizeof(t_csg));
	       h_csg->type =CSG_SPHERE;
				 h_csg->u_objet.sphere.prop.ambiant.red = 1.0;
				 h_csg->u_objet.sphere.prop.ambiant.green = 1.0;
				 h_csg->u_objet.sphere.prop.ambiant.blue = 1.0;
				 h_csg->u_objet.sphere.prop.diffuse.red = 1.0;
				 h_csg->u_objet.sphere.prop.diffuse.green = 1.0;
				 h_csg->u_objet.sphere.prop.diffuse.blue = 1.0;
				 h_csg->u_objet.sphere.prop.specular.red = 1.0;
				 h_csg->u_objet.sphere.prop.specular.green = 1.0;
				 h_csg->u_objet.sphere.prop.specular.blue = 1.0;
				 h_csg->u_objet.sphere.prop.reflect.red = 0.0;
				 h_csg->u_objet.sphere.prop.reflect.green = 0.0;
				 h_csg->u_objet.sphere.prop.reflect.blue = 0.0;
 	       h_csg->u_objet.sphere.prop.n = 1.0;
	       h_property = &h_csg->u_objet.sphere.prop; ;
    break;}
case 43:
#line 322 "scan.y"
{ h_csg = (t_csg *)alloca(sizeof(t_csg));
	      h_csg->type =CSG_PLANE;
	      h_csg->u_objet.plane.tile = 0.0;
				h_csg->u_objet.plane.prop.ambiant.red = 1.0;
				h_csg->u_objet.plane.prop.ambiant.green = 1.0;
				h_csg->u_objet.plane.prop.ambiant.blue = 1.0;
				h_csg->u_objet.plane.prop.diffuse.red = 1.0;
				h_csg->u_objet.plane.prop.diffuse.green = 1.0;
				h_csg->u_objet.plane.prop.diffuse.blue = 1.0;
				h_csg->u_objet.plane.prop.specular.red = 1.0;
				h_csg->u_objet.plane.prop.specular.green = 1.0;
				h_csg->u_objet.plane.prop.specular.blue = 1.0;
				h_csg->u_objet.plane.prop.reflect.red = 0.0;
				h_csg->u_objet.plane.prop.reflect.green = 0.0;
				h_csg->u_objet.plane.prop.reflect.blue = 0.0;
 	      h_csg->u_objet.plane.prop.n = 1.0;
	      org_csg = h_csg;
	      h_property = &h_csg->u_objet.plane.prop; ;
    break;}
case 49:
#line 352 "scan.y"
{ org_csg->u_objet.plane.tile = vallex_double; ;
    break;}
case 53:
#line 367 "scan.y"
{ temp_csg = (t_csg *)alloca(sizeof(t_csg));
		      						 temp_csg->type = CSG_TRANSLATION;
		       						 temp_csg->u_objet.translation.v = yyvsp[0].vecteur;
		       						 temp_csg->u_objet.translation.csg = h_csg;
		       						 h_csg = temp_csg; ;
    break;}
case 54:
#line 376 "scan.y"
{ temp_csg = (t_csg *)alloca(sizeof(t_csg));
		    						temp_csg->type = CSG_ROTATION;
		    						temp_csg->u_objet.rotation.r = yyvsp[0].vecteur;
		    						temp_csg->u_objet.rotation.csg = h_csg;
		    						h_csg = temp_csg; ;
    break;}
case 55:
#line 385 "scan.y"
{ temp_csg = (t_csg *)alloca(sizeof(t_csg));
	         			 temp_csg->type = CSG_SCALE;
		 						 temp_csg->u_objet.scale.s = yyvsp[0].vecteur;
								 temp_csg->u_objet.scale.csg = h_csg;
								 h_csg = temp_csg; ;
    break;}
case 61:
#line 404 "scan.y"
{ h_property->ambiant = yyvsp[0].composante; ;
    break;}
case 62:
#line 409 "scan.y"
{ h_property->diffuse = yyvsp[0].composante ;
    break;}
case 63:
#line 415 "scan.y"
{ h_property->reflect = yyvsp[0].composante ;
    break;}
case 64:
#line 420 "scan.y"
{ h_property->specular = yyvsp[0].composante ;
    break;}
case 65:
#line 424 "scan.y"
{ h_property->n = vallex_double; ;
    break;}
case 66:
#line 429 "scan.y"
{ yyvsp[0].val = vallex_double; ;
    break;}
case 67:
#line 430 "scan.y"
{ yyvsp[0].val = vallex_double; ;
    break;}
case 68:
#line 431 "scan.y"
{ yyvsp[0].val = vallex_double; ;
    break;}
case 69:
#line 433 "scan.y"
{ yyval.vecteur.x = yyvsp[-8].val;
	    yyval.vecteur.y = yyvsp[-5].val;
	    yyval.vecteur.z = yyvsp[-2].val; ;
    break;}
case 70:
#line 439 "scan.y"
{ yyvsp[0].val = vallex_double; ;
    break;}
case 71:
#line 440 "scan.y"
{ yyvsp[0].val = vallex_double; ;
    break;}
case 72:
#line 441 "scan.y"
{ yyvsp[0].val = vallex_double; ;
    break;}
case 73:
#line 443 "scan.y"
{ yyval.composante.red = yyvsp[-8].val;
	    yyval.composante.green = yyvsp[-5].val;
	    yyval.composante.blue = yyvsp[-2].val; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 450 "scan.y"



int yywrap(void)
{
  return(1);
}



void yyerror(char *s)
{
  /* evite que bison sorte des messages affreux... */
}