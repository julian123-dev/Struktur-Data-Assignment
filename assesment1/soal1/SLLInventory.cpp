#include "SLLInventory.h"

float hargaAkhir(Product P) {
    return P.HargaSatuan * (1 - P.DiskonPersen / 100);
}

bool isEmpty(List L) {
    return (L.head == NULL);
}

void createList(List &L) {
    L.head = NULL;
}

address allocate(Product P) {
    address N = new Node;
    N->info = P;
    N->next = NULL;
    return N;
}

void deallocate(address P) {
    delete P;
}

void insertFirst(List &L, Product P) {
    address N = allocate(P);
    N->next = L.head;
    L.head = N;
}

void insertLast(List &L, Product P) {
    address N = allocate(P);
    if (isEmpty(L)) {
        L.head = N;
    } else {
        address curr = L.head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = N;
    }
}

void insertAfter(List &L, address Q, Product P) {
    if (Q != NULL) {
        address N = allocate(P);
        N->next = Q->next;
        Q->next = N;
    }
}

void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        address del = L.head;
        P = del->info;
        L.head = del->next;
        deallocate(del);
    }
}

void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        address curr = L.head, prev = NULL;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }

        P = curr->info;

        if (prev == NULL)
            L.head = NULL;
        else
            prev->next = NULL;

        deallocate(curr);
    }
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q != NULL && Q->next != NULL) {
        address del = Q->next;
        P = del->info;
        Q->next = del->next;
        deallocate(del);
    }
}

void updateAtPosition(List &L, int posisi) {
    if (isEmpty(L)) return;

    address curr = L.head;
    int idx = 1;

    while (curr != NULL && idx < posisi) {
        curr = curr->next;
        idx++;
    }

    if (curr != NULL) {
        Product P;
        cout << "Masukkan Nama Baru: ";
        cin >> P.Nama;
        cout << "Masukkan SKU Baru: ";
        cin >> P.SKU;
        cout << "Masukkan Jumlah Baru: ";
        cin >> P.Jumlah;
        cout << "Masukkan Harga Satuan Baru: ";
        cin >> P.HargaSatuan;
        cout << "Masukkan Diskon Persen Baru: ";
        cin >> P.DiskonPersen;

        curr->info = P;
    }
}

void viewList(List L) {
    address curr = L.head;
    int pos = 1;

    cout << "\n=== Isi List ===\n";
    while (curr != NULL) {
        cout << pos << ". "
             << curr->info.Nama << " | "
             << curr->info.SKU << " | "
             << curr->info.Jumlah << " pcs | Rp"
             << curr->info.HargaSatuan
             << " | Diskon " << curr->info.DiskonPersen
             << "% | Harga Akhir: Rp" << hargaAkhir(curr->info)
             << endl;

        curr = curr->next;
        pos++;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    address curr = L.head;
    int pos = 1;

    cout << "\n=== Hasil Pencarian ===\n";

    while (curr != NULL) {
        float HA = hargaAkhir(curr->info);
        if (HA >= minPrice && HA <= maxPrice) {
            cout << pos << ". "
                 << curr->info.Nama << " | "
                 << curr->info.SKU << " | Harga Akhir Rp" << HA << endl;
        }
        curr = curr->next;
        pos++;
    }
}


void MaxHargaAkhir(List L) {
    if (isEmpty(L)) {
        cout << "\nList kosong.\n";
        return;
    }

    address curr = L.head;
    float maxHA = hargaAkhir(curr->info);

    
    curr = curr->next;
    while (curr != NULL) {
        float HA = hargaAkhir(curr->info);
        if (HA > maxHA)
            maxHA = HA;
        curr = curr->next;
    }

    
    curr = L.head;
    int pos = 1;

    cout << "\n=== Produk dengan Harga Akhir Terbesar ===\n";
    cout << "Harga Akhir Maksimum: Rp" << maxHA << "\n";

    while (curr != NULL) {
        float HA = hargaAkhir(curr->info);
        if (HA == maxHA) {
            cout << pos << ". "
                 << curr->info.Nama << " | "
                 << curr->info.SKU << " | "
                 << curr->info.Jumlah << " pcs | Rp"
                 << curr->info.HargaSatuan
                 << " | Diskon " << curr->info.DiskonPersen
                 << "% | Harga Akhir: Rp" << HA << endl;
        }
        curr = curr->next;
        pos++;
    }
}