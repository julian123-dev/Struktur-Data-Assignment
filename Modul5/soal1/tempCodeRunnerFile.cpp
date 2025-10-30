#include "Karyawan.h"

int main() {
    linkedList L;
    createList(L);

    address A = alokasi("Budi", "Manager", 7500000);
    address B = alokasi("Sinta", "Kasir", 4500000);
    address C = alokasi("Rian", "Staff", 4000000);
    address D = alokasi("Tono", "Security", 3500000);
    address E = alokasi("Dewi", "HRD", 7000000);

    insertFirst(L, A);
    insertLast(L, B);
    insertAfter(L, C, A);
    insertAfter(L, D, C);
    insertLast(L, E);

    printList(L);
    cout << "Jumlah node: " << nbList(L) << "\n\n";

    findByName(L, "Rian");
    findByAddress(L, C);
    findByRange(L, 4000000, 6000000);

    delFirst(L);
    delLast(L);
    delAfter(L, C);

    cout << "\nSetelah penghapusan:\n";
    printList(L);

    deleteList(L);

    return 0;
}

