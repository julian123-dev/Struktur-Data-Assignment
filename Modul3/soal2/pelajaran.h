#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};
pelajaran create_Pelajaran(string namapel, string kodepel);

void tampil_Pelajaran(pelajaran pel);

#endif