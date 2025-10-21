# <h1 align="center">Laporan Praktikum ModulSingly Linked List (Bagian Pertama)
</h1>
<p align="center">Julian Putra Pamungkas</p>

## Dasar Teori

Singly Linked List

Singly Linked List merupakan salah satu struktur data dinamis yang terdiri dari rangkaian node yang saling terhubung melalui pointer. Setiap node menyimpan dua bagian utama: data dan penunjuk (pointer) menuju node berikutnya. Berbeda dengan array yang elemen-elemennya disimpan secara berurutan di memori, node pada linked list bisa tersebar di berbagai lokasi memori namun tetap terhubung melalui pointer next.
Struktur ini merupakan bentuk implementasi dari list yang elemen-elemennya dihubungkan dengan pointer dan bukan disimpan secara bersebelahan di memori.
Keunggulan dari linked list adalah jumlah elemennya tidak harus ditetapkan sejak awal. Memori dapat dialokasikan dan dilepaskan secara dinamis selama program berjalan, sehingga operasi seperti penambahan dan penghapusan elemen dapat dilakukan dengan lebih mudah dan efisien.
Beberapa operasi dasar pada Singly Linked List antara lain:
createList() → Membuat list kosong.
alokasi() → Mengalokasikan node baru di memori.
insertFirst(), insertAfter(), dan insertLast() → Menambahkan node pada posisi awal, tengah, atau akhir list.
delFirst(), delAfter(), dan delLast() → Menghapus node dari posisi tertentu.
printList() → Menampilkan seluruh elemen dalam list.
nbList() → Menghitung jumlah node yang ada.
deleteList() → Menghapus semua node dalam list sekaligus.

## Guided 

### 1. [ADT Linked List (insert)]

```C++
//list.h
//header guar digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi dari linked listnya,isi setiap node adalah data & pointer new
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

//list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
} 

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//main.cpp
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Kode di atas digunakan untuk membuat Linked List dengan fungsi insert dengan menambahkan node dan menampilkan hasil insert.

### 2. [ADT Linked List (insert, delete, count, clear)]

```C++
//list.h
//header guar digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi dari linked listnya,isi setiap node adalah data & pointer new
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

//list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
} 

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//main.cpp
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Kode di atas berfungsi sebagaai membuat ADT Linked List dengan beberapa fungsi tambahan dari sebelumnya yaitu fungsi untuk menghapus node, alokasi, manipulasi, dealokasi pada data dan menampilkan jumlah node setelah penghapusan.

## Unguided 

### 1. [ADT Singly Linked]
a. [Header File]
```C++
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

```


b. [Source File]
```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) { 
    address NewNode = new Elmlist; 
    NewNode->data = x;
    NewNode->next = Nil;
    return NewNode;
}

void dealokasi(address p) {
    delete p;
}

void printInfo(List L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Masih kosong" << endl;
    } else {
        cout << "Isi List: ";
        while (P != Nil) {
            cout << P->data << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

```

c. [Main Program]
```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}

``` 
Output:
<img width="982" height="76" alt="Image" src="https://github.com/user-attachments/assets/f36f03fe-3f06-4488-ba4f-ed3c0885a23f" />

Program ini menerapkan ADT Singly Linked List untuk menyimpan data secara dinamis. Struktur node berisi data dan pointer ke node berikutnya. Melalui fungsi insertAwal, insertAkhir, dan insertAfter, data dimasukkan ke dalam list, kemudian seluruh isi list ditampilkan ke layar.

Full code Screenshot:
<img width="1917" height="1012" alt="Image" src="https://github.com/user-attachments/assets/b56e2a03-c9bd-4a54-98a3-9912e7c5aef8" />

### 2. [ADT Singly Linked++]
a. [Header File]
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;

struct Elmlist;  
typedef Elmlist* address; 

struct Elmlist {
    infotype data;
    address next;
};

struct List {
    address first;
};


void CreateList(List &L); 
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);

void delFirst(List &L);
void delLast(List &L);
void delAfter(List &L, address nodeHapus, address nodePrev);
int nbList(List L);
void deleteList(List &L);

#endif

```


b. [Source File]
```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {

    L.first = Nil;
}

address alokasi(infotype x) { 
    address NewNode = new Elmlist ; 
    NewNode->data = x;
    NewNode->next = Nil;
    return NewNode;
}

void dealokasi(address p) {
    delete p;
}

void printInfo(List L) {
    address P = L.first;
    int jumlah = 0;
    if (P == Nil) {
        cout << "List kosong" << endl;
    } else {
        cout << " ";
        while (P != Nil) {
            cout << P->data << " ";
            jumlah++;
            P = P->next;
        }
        cout << endl;
        cout << "Jumlah node : " << jumlah << endl;
    }
}

void insertFirst(List &L, address p) {
    p->next = L.first;
    L.first = p;
}

void delFirst(List &L){
    address nodeHapus;
    if (L.first != Nil) {
        nodeHapus = L.first;
        L.first = L.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(List &L){
    address nodeHapus, nodePrev;
    if(L.first != Nil){
        nodeHapus = L.first;
        if(nodeHapus->next == Nil){
            L.first = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(List &L, address nodeHapus, address nodePrev){
    if(L.first == Nil){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

int nbList(List L) {
    int count = 0;
    address nodeBantu = L.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(List &L){
    address nodeBantu, nodeHapus;
    nodeBantu = L.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    L.first = Nil; 
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : 0" << endl;
}

```

c. [Main Program]
```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    delFirst(L);
    delLast(L);
    delAfter(L, NULL, L.first);

    printInfo(L);

    deleteList(L);

    return 0;
}
```
Output:
<img width="1130" height="143" alt="Image" src="https://github.com/user-attachments/assets/98da70ce-1eff-4f55-a3c7-413571235cac" />

Program ini merupakan pengembangan dari ADT Single Linked sebelumnya, tapi ada tambahan beberapa fungsi untuk hapus data dan hitung jumlah node. Strukturnya masih pakai node dengan data dan pointer next. Bedanya, sekarang ada fungsi deleteFirst, deleteLast, deleteAfter, nbList, dan deleteList. Jadi selain bisa nambah data lewat insertAwal, insertAkhir, dan insertAfter, program ini juga bisa hapus dan bersihin list.

Full code Screenshot:
<img width="1908" height="998" alt="Image" src="https://github.com/user-attachments/assets/290eb17d-2b19-4c82-aa49-6f3562321dea" />


## Kesimpulan
Secara keseluruhan, modul dan praktikum Singly Linked List membahas cara mengelola data secara dinamis menggunakan node yang saling terhubung. Materi mencakup proses penambahan, penghapusan, hingga perhitungan data dalam list.

## Referensi
[1] Analysis of Arraylist dan Linked List oleh: K. Renuka Devi. Diakses pada 20 Oktober 2025 melalui:
https://www.scribd.com/document/756597574/263-IJCSE-07046-23?utm
[2] Review Paper On Dynamic Implementation Using Linked List oleh: Manish saini, Ankush Sharma. Diakses pada 20 Oktober 2025 melalui:
https://www.researchgate.net/publication/329609389_Review_Paper_On_Dynamic_Implementation_Using_Linked_List_Chandigarh_universty.
