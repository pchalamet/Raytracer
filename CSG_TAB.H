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


extern YYSTYPE yylval;
