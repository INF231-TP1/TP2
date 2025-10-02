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
ListeSChainee ajoutElementSC(ListeSChainee t);
ListeDChainee ajoutElementDC(ListeDChainee t);
ListeSChainee suppOccurenceSC(ListeSChainee t);
ListeDChainee suppOccurenceDC(ListeDChainee t);
void affichageSC(ListeSChainee t);
void affichageDC(ListeDChainee t);
void affichageSCC(ListeSChaineeC t);
void affichageDCC(ListeDChaineeC t);
ListeSChaineeC ajoutTeteSCC(ListeSChaineeC t);
ListeDChaineeC ajoutTeteDCC(ListeDChaineeC t);
ListeSChaineeC ajoutQueueSCC(ListeSChaineeC t);
ListeDChaineeC ajoutQueueDCC(ListeDChaineeC t);


#endif
