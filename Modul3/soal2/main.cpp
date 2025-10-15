#include <iostream>
#include "Pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_Pelajaran(namapel, kodepel);
    tampil_Pelajaran(pel);

    return 0;
}