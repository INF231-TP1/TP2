#ifndef _TP2_
#define _TP2_


typedef struct Liste{
    struct Liste *prev;
    int val;
    struct Liste *next;
}*Liste;
int lireEntier(const char* message, int min, int max);
int LireMot(const char* message, char* chaine, size_t tailleChaine);
Liste init();
Liste last(Liste t);
Liste inserthead(Liste t, int v);
Liste insertbottom(Liste t, int v);
Liste deletehead(Liste t);
Liste deletebottom(Liste t);
Liste sortascending(Liste t);
Liste sortdescending(Liste t);


#endif
