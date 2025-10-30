#ifndef KARYAWAN_H
#define KARYAWAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct karyawan {
    string nama;
    string jabatan;
    float gaji;
};

typedef karyawan dataKaryawan; 

typedef struct node *address; 

struct node { 
    dataKaryawan isidata;
    address next;
};

struct linkedList {
    address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);

address alokasi(string nama, string jabatan, float gaji);
void dealokasi(address &node);

void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);

void printList(linkedList List);
int nbList(linkedList List);
void deleteList(linkedList &List);

void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address Prev);

void FindNodeByData(linkedList list, string data);
void FindNodeByAddress(linkedList list, address node);
void FindNodeByRange(linkedList list, float gajiAwal, float gajiAkhir);

#endif
