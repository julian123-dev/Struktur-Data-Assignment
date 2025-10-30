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
