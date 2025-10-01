# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Julian Putra Pamungkas </p>

## Dasar Teori

Penjelasan teori terkait materi modul ini adalah. Aritmatika adalah cabang ilmu matematika yang membahas perhitungan dasar "kabataku", yakni operasi perkalian, pembagian, penambahan dan pengurangan. Struktur perulangan (atau dalam bahasa inggris disebut loop) adalah instruksi kode program yang bertujuan untuk mengulang beberapa baris perintah.

## Guided 

### 1. [Aritmatika]

```C++
#include <iostream>
using namespace std;

int main () {
    int a;
    int b;
    
    cout << "Masukan angka1: ";
    cin >> a;
    cout << "Masukan angka2: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //Operator logika
    cout << "a > b = " << (a>b) << endl;
    cout << "a < b = " << (a<b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;
    return 0;
}
```
## Unguided 

### 1. [Soal unguided 1]

Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil 
penjumlahan,pengurangan,perkalian,dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>

using namespace std;

int main(){
    float angka1, angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    cout << "Penjumlahan : " << angka1 + angka2 << endl;
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    cout << "Perkalian : " << angka1 * angka2 << endl;
    cout << "Pembagian : " << angka1 / angka2 << endl;
    return 0;
}
```
Program diatas berfungsi sebagai kalkulator sederhana yang dapat menjumlahkan, mengurangkan, mengalikan, dan membagi dua angka yang dimasukkan oleh pengguna.

#### Output:
![240302_00h00m06s_screenshot](https://github.com/julian123-dev/103112400241_Julian_Putra_Pamungkas/blob/main/foto/soal-1.png)


#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/julian123-dev/103112400241_Julian_Putra_Pamungkas/blob/main/foto/full-soal-1.png)

### 2. [Soal unguided 2]

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan.Angka yang akan diinput kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
#include <iostream>

using namespace std;

int main(){
    string satuan[9] = {"satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan",};
    string belasan[9] = {"sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[9] = {"sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    int angka;
    cout << "Masukkan Angka: ";
    cin >> angka;

    if (angka < 10) {
        cout << satuan[angka - 1] << endl;
    } else if (angka < 20) {
        cout << belasan[angka - 11] << endl;
    } else if (angka %10 == 0) {
        cout << puluhan[angka / 10 - 1] << endl;
    } else if (angka == 100) {
        cout << "seratus" << endl;
    } else if (angka > 20 && angka < 100) {
        cout << puluhan[ (angka/10)-1 ] << " " << satuan[ (angka%10)-1 ] << endl;
    }

    return 0;
} 
```
Program diatas berfungsi sebagai program konversi angka menjadi kata dalam bahasa Indonesia untuk angka antara 1 hingga 100.

#### Output:
![240302_00h00m06s_screenshot](https://github.com/julian123-dev/103112400241_Julian_Putra_Pamungkas/blob/main/foto/soal2.png)


#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/julian123-dev/103112400241_Julian_Putra_Pamungkas/blob/main/foto/full-soal2.png)

### 3. [Soal unguided 3]

Buatlah program yang dapat memberikan input dan output sbb

```C++
#include <iostream>
using namespace std;

int main(){
    int n, i;
    cout << "Masukkan Inputan : ";
    cin >> n;

    for (int i = n; 0 <  i; i--) {
        cout << i;
    } 
    cout << "*";

    for (int i = 1; i <= n; i++) {
        cout << i;
    }

    cout << endl;
    n = n - 1;

    int spasi = 1;

    while (n >= 0) {

        for (int i = 0; i < spasi; i++) {
            cout << " ";
        }
        for (int i = n; 0 < i; i--) {
            cout << i;
        } 
            cout << "*";

        for (int i = 1; i <= n; i++) {
            cout << i;
        } 
        cout << endl;
        n = n - 1;
        spasi++;
    }
} 
```
Program diatas berfungsi untuk menampilkan pola angka simetris berbentuk segitiga terbalik,
di mana setiap baris berisi angka menurun di kiri, tanda bintang (*) di tengah, dan angka menaik di kanan.

#### Output:
![240302_00h00m06s_screenshot](https://github.com/julian123-dev/103112400241_Julian_Putra_Pamungkas/blob/main/foto/soal3.png)


#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/julian123-dev/103112400241_Julian_Putra_Pamungkas/blob/main/foto/full-soal3.png)


## Kesimpulan
Modul ini mengenalkan. Penggunaan Code::Blocks IDE untuk C++.
Struktur dasar program C++.
Penggunaan input/output, variabel, operator, dan komentar.
Dasar debugging melalui kesalahan umum dalam kode..

## Referensi
[1]https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-aritmatika-bahasa-c-plus-plus/

[2]https://www.duniailkom.com/tutorial-belajar-c-plus-plus-perulangan-for-bahasa-c-plus-plus/