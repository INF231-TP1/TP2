#ifndef _TP2_
#define _TP2_


typedef struct ListeSChainee{
    int val;
    struct ListeSChainee *next;
}*ListeSChainee;
typedef struct ListeDChainee{
    struct ListeDChainee *prev;
    int val;
    struct ListeDChainee *next;
}*ListeDChainee;
int lireEntier(const char* message, int min, int max);
ListeSChainee ajoutElementSC(ListeSChainee t);
ListeDChainee ajoutElementDC(ListeDChainee t);
ListeSChainee suppOccurenceSC(ListeSChainee t);
ListeDChainee suppOccurenceDC(ListeDChainee t);
void affichageSC(ListeSChainee t);
void affichageDC(ListeDChainee t);
void affichageSCC(ListeSChainee t);
void affichageDCC(ListeDChainee t);
ListeSChainee ajoutTeteSCC(ListeSChainee t);
ListeDChainee ajoutTeteDCC(ListeDChainee t);
ListeSChainee ajoutQueueSCC(ListeSChainee t);
ListeDChainee ajoutQueueDCC(ListeDChainee t);


#endif
