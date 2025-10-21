#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil nullptr   

typedef int infotype; 
typedef struct Elmlist *address;

struct Elmlist {
    infotype data;
    address next;
};

struct List {
    address first;
};

// Deklarasi fungsi
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address p);
void printInfo(List L);
void insertFirst(List &L, address p);

#endif
