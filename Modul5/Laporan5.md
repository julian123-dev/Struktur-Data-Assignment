# <h1 align="center">Laporan Praktikum Modul Singly Linked List (Bagian Kedua)</h1>
<p align="center">Julian Putra Pamungkas</p>

## Dasar Teori

Pencarian (searching) adalah operasi dasar dalam sebuah list yang berfungsi untuk menemukan node tertentu dengan cara memeriksa setiap node satu per satu hingga node yang diinginkan ditemukan. Proses ini mempermudah pelaksanaan operasi seperti menyisipkan setelah node tertentu (insert after), menghapus setelah node tertentu (delete after), dan memperbarui data (update). Semua fungsi dasar ini merupakan bagian dari Abstract Data Type (ADT) dalam singly linked list dan diimplementasikan dalam file .c dan .h.
Dalam linked list, proses pencarian berjalan lambat karena harus menelusuri node satu per satu, yang disebut dengan sequential search.
Namun, kecepatan pencarian dapat ditingkatkan dengan menambahkan indeks pada list.
Teknik seperti menambahkan lane linked list sebagai indeks dapat membantu melewati beberapa node, sehingga proses pencarian menjadi lebih cepat.
Kita menggunakan lane untuk mengunjungi dan memeriksa jumlah node seminimal mungkin. Saat menggunakan lane, beberapa node antara lane saat ini dan lane sebelumnya akan dilewati berdasarkan pembagian yang telah ditentukan. Dengan melewati node-node ini, waktu yang diperlukan untuk memeriksa node di antara dua lane dapat dihemat.
Dengan cara ini, meskipun ADT dari singly linked list sangat berguna untuk operasi yang bersifat dinamis, aspek pencarian tetap memerlukan perhatian dan optimasi khusus untuk meningkatkan kinerjanya.

## Guided   

### 1. [ListBuah]
a. [Header File]
```C++
//header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct buah
struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias dataBuah untuk struct buah

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata; //disamakan dengan di list.cpp
    address next;
};

struct linkedList { 
    address first;
};

//Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);

address alokasi(string nama, int jumlah, float harga);

void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);
void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address Prev);
void FindNodeByData(linkedList list, string data);
void FindNodeByAddress(linkedList list, address node);
void FindNodeByRange(linkedList list, float hargaAwal, float HargaAkhir);

#endif

```

b. [Source File]
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedList list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedList list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedList list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

c.[Main Program]
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List; // nama struct disamakan (linkedList)
    address nodeA = Nil, nodeB = Nil, nodeC = Nil, nodeD = Nil, nodeE = Nil; // semua diinisialisasi Nil
    createList(List);

    // Pembuatan node baru (alokasi data buah)
    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 11450);

    // Proses insert node ke dalam list
    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << nbList(List) << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl; 

    return 0;
};
```
Program ini mengimplementasikan ADT Singly Linked List dalam C++ untuk mengelola data buah. Konsep yang digunakan meliputi node, pointer, dan manajemen memori dinamis guna melakukan operasi penyimpanan, penambahan, penghapusan, pembaruan, serta pencarian data.

## Unguided 

### 1. [Soal]
a. [Header File]
```C++
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

```
b. [Source File]
```C++
#include "Karyawan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    return List.first == Nil;
}


void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, string jabatan, float gaji) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jabatan = jabatan;
    nodeBaru->isidata.gaji = gaji;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedList &List) {
    if (!isEmpty(List)) {
        address nodeHapus = List.first;
        List.first = nodeHapus->next;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
        return;
    }
    address nodeHapus = List.first, nodePrev = Nil;
    if (nodeHapus->next == Nil) {
        dealokasi(nodeHapus);
        List.first = Nil;
    } else {
        while (nodeHapus->next != Nil) {
            nodePrev = nodeHapus;
            nodeHapus = nodeHapus->next;
        }
        nodePrev->next = Nil;
        dealokasi(nodeHapus);
    }
    cout << "Node terakhir berhasil dihapus!" << endl;
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    if (!isEmpty(List) && nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        dealokasi(nodeHapus);
        cout << "Node setelah " << nodePrev->isidata.nama << " dihapus!" << endl;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        cout << "=== Data Karyawan ===" << endl;
        while (nodeBantu != Nil) {
            cout << "Nama: " << nodeBantu->isidata.nama
                 << " | Jabatan: " << nodeBantu->isidata.jabatan
                 << " | Gaji: Rp" << nodeBantu->isidata.gaji << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedList &List) {
    address nodeBantu = List.first, nodeHapus;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "Semua node berhasil dihapus!" << endl;
}

void updateFirst(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan data baru untuk node pertama:\n";
        cout << "Nama: "; cin >> List.first->isidata.nama;
        cout << "Jabatan: "; cin >> List.first->isidata.jabatan;
        cout << "Gaji: "; cin >> List.first->isidata.gaji;
    }
}

void updateLast(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) nodeBantu = nodeBantu->next;
        cout << "Masukkan data baru untuk node terakhir:\n";
        cout << "Nama: "; cin >> nodeBantu->isidata.nama;
        cout << "Jabatan: "; cin >> nodeBantu->isidata.jabatan;
        cout << "Gaji: "; cin >> nodeBantu->isidata.gaji;
    }
}

void updateAfter(linkedList List, address Prev) {
    if (!isEmpty(List) && Prev != Nil && Prev->next != Nil) {
        address nodeBantu = Prev->next;
        cout << "Masukkan data baru untuk node setelah " << Prev->isidata.nama << ":\n";
        cout << "Nama: "; cin >> nodeBantu->isidata.nama;
        cout << "Jabatan: "; cin >> nodeBantu->isidata.jabatan;
        cout << "Gaji: "; cin >> nodeBantu->isidata.gaji;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void FindNodeByData(linkedList list, string data) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }
    address nodeBantu = list.first;
    int posisi = 0;
    bool found = false;
    while (nodeBantu != Nil) {
        posisi++;
        if (nodeBantu->isidata.nama == data) {
            cout << "Karyawan " << data << " ditemukan di posisi ke-" << posisi << endl;
            cout << "Jabatan: " << nodeBantu->isidata.jabatan << ", Gaji: Rp" << nodeBantu->isidata.gaji << endl;
            found = true;
            break;
        }
        nodeBantu = nodeBantu->next;
    }
    if (!found) cout << "Data karyawan " << data << " tidak ditemukan!" << endl;
}

void FindNodeByAddress(linkedList list, address node) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }
    address nodeBantu = list.first;
    int posisi = 0;
    while (nodeBantu != Nil) {
        posisi++;
        if (nodeBantu == node) {
            cout << "Node ditemukan di posisi ke-" << posisi << endl;
            cout << "Nama: " << nodeBantu->isidata.nama << " | Jabatan: " << nodeBantu->isidata.jabatan << " | Gaji: Rp" << nodeBantu->isidata.gaji << endl;
            return;
        }
        nodeBantu = nodeBantu->next;
    }
    cout << "Node tidak ditemukan dalam list!" << endl;
}

void FindNodeByRange(linkedList list, float gajiAwal, float gajiAkhir) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }
    address nodeBantu = list.first;
    int posisi = 0;
    bool found = false;
    cout << "--- Karyawan dengan gaji antara Rp" << gajiAwal << " - Rp" << gajiAkhir << " ---" << endl;
    while (nodeBantu != Nil) {
        posisi++;
        float gaji = nodeBantu->isidata.gaji;
        if (gaji >= gajiAwal && gaji <= gajiAkhir) {
            cout << posisi << ". " << nodeBantu->isidata.nama << " (" << nodeBantu->isidata.jabatan << ") - Rp" << gaji << endl;
            found = true;
        }
        nodeBantu = nodeBantu->next;
    }
    if (!found) cout << "Tidak ada karyawan dalam rentang gaji tersebut." << endl;
}

```
c. [Main Program]
```C++
#include "karyawan.h"
#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address A = Nil, B = Nil, C = Nil, D = Nil, E = Nil;

    createList(List);

    A = alokasi("Budi", "Manager", 7500000);
    B = alokasi("Sinta", "Kasir", 4500000);
    C = alokasi("Rian", "Staff", 4000000);
    D = alokasi("Tono", "Security", 3500000);
    E = alokasi("Dewi", "HRD", 7000000);

    insertFirst(List, A);
    insertLast(List, B);
    insertAfter(List, C, A);
    insertAfter(List, D, C);
    insertLast(List, E);

    cout << "--- ISI LIST SETELAH INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl << endl;

   
    updateFirst(List);
    updateLast(List);
    updateAfter(List, D);

    cout << "--- SETELAH UPDATE ---" << endl;
    printList(List);
    cout << endl;

    FindNodeByData(List, "Rian");
    FindNodeByAddress(List, C);
    FindNodeByRange(List, 4000000, 7000000);

   
    delFirst(List);
    delLast(List);
    delAfter(List, D, C);

    cout << "--- ISI LIST SETELAH DELETE ---" << endl;
    printList(List);
    cout << endl;

    
    deleteList(List);
    cout << "Jumlah node akhir : " << nbList(List) << endl;

    return 0;
}

```
#### Output:



Program ini berfungsi untuk mengelola data karyawan menggunakan struktur data Singly Linked List (SLL) dalam bahasa C++, yang mencakup operasi dasar seperti menambah, menghapus, memperbarui, menampilkan, serta mencari data karyawan.

#### Full code Screenshot:



## Kesimpulan
Ssingly linked list dapat digunakan untuk menampilkan data, mencari elemen tertentu, dan menghitung total nilai elemen dengan bantuan fungsi findElm() dan totalInfo().

## Referensi
[1] [1] Analysis of Arraylist dan Linked List oleh: Sarvesh Rakesh Bhatnagar. Diakses pada 28 Oktober 2025 melalui:
https://www.scribd.com/document/756597574/263-IJCSE-07046-23?utm
