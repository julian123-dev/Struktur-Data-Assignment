#include <iostream>
#include "SLLInventory.h"
using namespace std;

int main() {
    List L;
    createList(L);

    Product P;

    P = {"Pulpen", "A001", 20, 2500, 0};
    insertLast(L, P);

    P = {"Buku Tulis", "A002", 15, 5000, 10};
    insertLast(L, P);

    P = {"Penghapus", "A003", 30, 1500, 0};
    insertLast(L, P);

    viewList(L);

    Product deleted;
    deleteFirst(L, deleted);

    viewList(L);

    cout << "\nUpdate posisi ke-2:\n";
    updateAtPosition(L, 2);

    viewList(L);


    cout << "\nSearching harga akhir 2000 - 7000:\n";
    searchByFinalPriceRange(L, 2000, 7000);

    MaxHargaAkhir(L);

    return 0;
}