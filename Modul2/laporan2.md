# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (Bagian Kedua) (1)</h1>
<p align="center">Julian Putra Pamungkas</p>

## Dasar Teori

C adalah bahasa pemrograman terstruktur yang membagi program dalam bentuk sejumlah blok. Tujuannya adalah untuk memudahkan dalam pembuatan dan pengembangan program. Program C++ biasa ditulis dengan nama ekstensi .CPP (dari kata C plus plus). Agar program ini dapat dijalankan (dieksekusi), program harus dikompilasi lebih dulu dengan menggunakan kompiler C++.

1. Array
Array merupakan suatu struktur data yang terdiri dari sekumpulan data dengan tipe data yang sama dan setiap data yang disimpan kedalam alamat memori disebun elemen array. Ada juga yang disebut array 2 dimensi yaitu perluasan dari konsep array satu dimensi dan array 2 dimensi ini berbentuk matriks dan elemen nya dibentuk dari baris dan kolom sehingga dapat mempresentasikan data yang lebih kompleks lagi.[3]

2. Function
Function merupakan sebuah blok kode yang dapat menerima input dari pemanggilnya,melakukan serangkaian operasi,dan dapat secara opsional mengembalikan nilai sebagai output.

3. Procedure
Prosedur adalah sederetan intruksi algoritma yang diberi nama,dan akan menghasilkan efek neto yang terdefinisi.

4. Pointer
Pointer dalam C++ merupakan sebuah variabel yang menunjuk alamat memori variabel lain. Pointer memungkinkan kita unutuk melakukan manipulasi secara langsung terhadap variabel lain di dalam memori.

5. Reference
Reference adalah sebuah variabel yang berfungsi sebagai pemberi alias untuk variabel yang ada / menyediakan nama alternatif untuk variabel dan memungkinkan bekerja dengan data asli secara langsung.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>

using namespace std;

int main () {
    // array 1 dimensi
    int arrID[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi" << endl;
    for (int i=0; i<5; i++) {
        cout << "arrID" << i << " = " << arrID[i] << endl; 
        
    }
    cout << endl;

    // array 2 dimensi baris & kolom
    int arr2D[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    cout << "Array 2 Dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            cout << "arr2D[" << i << "}[" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //array multi dimensi (3D)
    int arr3D[2][2][3] = {
    { { 1, 2, 3 }, {4, 5, 6} },
    { { 7, 8, 9} , {10, 11, 12} }   
    };
    cout << "array 3 dimensi" << endl;
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Program ini berfungsi untuk menunjukkan cara membuat dan menampilkan array 1 dimensi, 2 dimensi, dan 3 dimensi di C++, serta menampilkan semua elemennya ke layar menggunakan perulangan for.

### 2. [prosedur dan fungsi]

```C++
#include <iostream>
using namespace std;

void tulis (int x){
    for (int i = 0; 1 < x; i++ ){
        cout << "Baris ke -: " << i+1 << endl;
    
    }
}

int main () {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    
    return 0;
}
```
Program ini berfungsi untuk menampilkan tulisan “Baris ke - …” sebanyak jumlah baris yang dimasukkan pengguna, menggunakan fungsi void berparameter bernama tulis().

### 2. [prosedur dan fungsi]

```C++
#include <iostream>
using namespace std;

void tulis (int x){
    for (int i = 0; 1 < x; i++ ){
        cout << "Baris ke -: " << i+1 << endl;
    
    }
}

int main () {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    
    return 0;
}
```
Program ini berfungsi untuk menampilkan tulisan “Baris ke - …” sebanyak jumlah baris yang dimasukkan pengguna, menggunakan fungsi void berparameter bernama tulis().


### 3. [pointer]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y){
int temp;
temp = *x;
*x = *y;
*y = temp;
}


int main (){
   int a = 20, b = 30;
   int *ptr;

   ptr= &a;

   cout << "Value of a: " << a << endl;
    cout << "Addres of a: " << &a << endl;
     cout << "Value stored in ptr (adrres of a): " << ptr << endl;
      cout << "Value pointed to by ptr: " << *ptr << endl;
 
      tukar (&a, &b);
      cout << "After swapping, Value of a=" << a << "and b=" << b << endl;

      return 0;

}
```
Program ini berfungsi untuk menampilkan nilai, alamat memori, dan isi dari sebuah pointer,
serta menukar nilai dua variabel (a dan b) menggunakan pointer.


### 3. [reference]

```C++
#include <iostream>
using namespace std;

   void tukar(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}


int main (){
   int a = 20, b = 30;
   int &ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref a (alias a): " << ref << endl;
    cout << "Alamat ref (ref): " << &ref << endl;

      // mengubah nilai a lewat reaference
       ref = 50;
       cout << "\n setelelah ref = 50;" << endl;
       cout << "Nilai a: " << a << endl;
       cout << "Nilai ref: " << ref << endl;

 
      tukar (a, b);
      cout << "After swapping, Value of a=" << a << "and b=" << b << endl;

      return 0;

}
```
Program ini berfungsi untuk menunjukkan cara kerja reference (&) di C++,

## Unguided 

### 1. [Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3]

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[3][3] = {
        {1, 2, 4},
        {3, 4, 6},
        {2, 1, 8}
    };
    int arrB[3][3] = {
        {2, 3, 5},
        {4, 5, 2},
        {8, 1, 9}
    };
    int arrC[3][3] = {0}; 
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

 
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil pengurangan : " << endl;
    tampilkanHasil(arrD);

    cout << endl;


    for (int i = 0; i < 3; i++) {            
        for (int j = 0; j < 3; j++) {       
            for (int k = 0; k < 3; k++) {  
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrE);

    return 0;
}
```
<img width="772" height="215" alt="Image" src="https://github.com/user-attachments/assets/036acb11-364f-4462-9441-f8f3a24f65bc" />

Program ini berfungsi untuk menghitung dan menampilkan hasil operasi penjumlahan, pengurangan, dan perkalian antara dua matriks 3x3

### 2. [ Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.]

```C++
#include <iostream>
using namespace std;


void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;   
    *a = *b;         
    *b = *c;         
    *c = temp;     
}
void tukarReference(int &a, int &b, int &c) {
    int temp = a;   
    a = b;          
    b = c;           
    c = temp;       
}
int main() {
    int x = 10, y = 20, z = 30;

    cout << "Sebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarPointer(&x, &y, &z);
    cout << "\nSetelah ditukar dengan Pointer:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    tukarReference(x, y, z);
    cout << "\nSetelah ditukar dengan Reference:" << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}

```
<img width="799" height="113" alt="Image" src="https://github.com/user-attachments/assets/f45dc36c-25ac-45a4-910e-d3c655addc05" />

Program ini menunjukkan dua cara berbeda untuk menukar nilai dari tiga variabel:
Dengan pointer (menggunakan alamat memori)
Dengan reference (menggunakan alias variabel langsung)

### 3. [ Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel.]

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[], int n){
    cout << "Isi array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

int cariMIN(int arr[], int ukuran){
    int MIN = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] < MIN){
            MIN = arr[i];
        }
    }
    return MIN;
}

float NilaiRataRata(int arr[], int n){
    int total = 0;
    for(int i = 0; i < n; i++){
        total += arr[i];
    }
    return (float)total / n;
}

int main() {
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int inputan;

    do {
        cout << "\n-- Menu Program Array --\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Inputan: ";
        cin >> inputan;

        switch (inputan){
            case 1:
                tampilArray(arrA, 10); break;
            case 2:
                cout << "Nilai Maksimumnya adalah: " << cariMAX(arrA, 10) << endl; break;
            case 3:
                cout << "Nilai Minimumnya adalah: " << cariMIN(arrA, 10) << endl; break;
            case 4:
                cout << "Nilai rata ratanya adalah: " << NilaiRataRata(arrA, 10) << endl; break;
            case 5:
                cout << "Program selesai\n"; break;
        }
    } while (inputan != 5);

    return 0;
}

```

Program ini digunakan untuk mempelajari operasi dasar pada array, seperti:
Traversing (menampilkan isi)
Mencari nilai maksimum dan minimum
Menghitung rata-rata elemen array
Menggunakan fungsi dan menu interaktif



#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Dalam pertemuan ini,mahasiswa diajarkan bagaimana cara membuat menu sederhana dengan beberapa fungsi dan prosedur serta mahasiswa bisa mengubah nilai variabel dengan menggunakan 2 cara yaitu pointer serta reference.

## Referensi
[1] Konsep Dasar Algoritma dan Pemograman Menggunakan C++ Chapter#1. Diakses pada 28 September 2025 melalui https://repository.unpkediri.ac.id/2466/1/55201_0701107802.pdf. [2] Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++ Oleh Shofwan Hanief, S.Kom., M.T., I Wayan Jepriana, S.Kom., M.Cs. Diakses pada 4 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=BRQQEAAAQBAJ&oi=fnd&pg=PP1&dq=bahasa+pemrograman+c%2B%2B+array+&ots=0DeP7JvQiX&sig=ljOtCM5nabUNTAs6uY8T44eGlmU&redir_esc=y#v=onepage&q=array&f=false. [3] Algoritma dan Pemrograman: Konsep Dasar, Logika, dan Implementasi dengan C++ & Phyton Oleh Rozzi Kesuma Dinata, Novia Hasdyna. Diakses pada 4 Oktober 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=6kBlEQAAQBAJ&oi=fnd&pg=PA1&dq=bahasa+pemrograman+c%2B%2B+array+2+dimensi&ots=bk_HFcsTHF&sig=Mu99cJIpT_eMiFE9BXV2aFZko5E&redir_esc=y#v=onepage&q&f=false. [4] Funtion C++: Panduan Lengkap. Diakses pada 4 Oktober 2025 melalui https://www.kodingakademi.id/function-c-panduan-lengkap/. [5] PROGRAM STUDI KOMPUTERISASI AKUNTANSI AMIK BSI PONTIANAK 2016. Diakses pada 4 Oktober 2025 melalui https://repository.bsi.ac.id/repo/files/237654/download/20161---Algoritma-dan-Pemrograman.pdf.
