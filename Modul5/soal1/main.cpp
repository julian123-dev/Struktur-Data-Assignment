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
