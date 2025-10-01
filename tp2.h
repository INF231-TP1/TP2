#ifndef _TP2_
#define _TP2_


typedef struct Liste{
    struct Liste *prev;
    int val;
    struct Liste *next;
}*Liste;
int lireEntier(const char* message, int min, int max);
Liste init();
Liste last(Liste t);
Liste inserthead(Liste t, int v);
Liste insertbottom(Liste t, int v);
Liste deletehead(Liste t);
Liste deletebottom(Liste t);
Liste sortascending(Liste t);
Liste sortdescending(Liste t);


#endif
