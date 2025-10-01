#ifndef _TP2_
#define _TP2_


typedef struct ListeSChainee{
    int val;
    struct ListeSChainee *next;
}*ListeSChainee;
typedef struct ListeSChaineeC{
    int indice;
    int val;
    struct ListeSChaineeC *next;
}*ListeSChaineeC;
typedef struct ListeDChainee{
    struct ListeDChainee *prev;
    int val;
    struct ListeDChainee *next;
}*ListeDChainee;
typedef struct ListeDChaineeC{
    int indice;
    struct ListeDChaineeC *prev;
    int val;
    struct ListeDChaineeC *next;
}*ListeDChaineeC;
int lireEntier(const char* message, int min, int max);
ListeSChainee last(ListeSChainee t);
ListeSChainee ajoutElementSC(ListeSChainee t);
ListeSChainee suppOccurenceSC(ListeSChainee t);
void affichage(ListeSChainee t);
void affichageC(ListeSChaineeC t);
ListeSChaineeC ajoutTeteSCC(ListeSChaineeC t);
ListeSChaineeC ajoutQueueSCC(ListeSChaineeC t);


#endif
