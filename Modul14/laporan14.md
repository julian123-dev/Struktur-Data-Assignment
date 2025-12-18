# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Julian Putra Pamungkas</p>

## Dasar Teori

Teori graf adalah studi yang menarik dalam matematika diskrit yang berfokus pada sifat-sifat graf. Ilmu graf ini telah diterapkan di berbagai bidang. Sebuah graf G didefinisikan sebagai sepasang himpunan V dan E (V,E),di mana V merujuk pada himpunan titik yang tidak boleh kosong, sementara E menunjukkan himpunan sisi yang menghubungkan pasangan titik pada graf.[1]
1. DFS (Depth First Search) Searching
Pada setiap pencabangan,penelusuran verteks-verteks yang belum dikunjungi dilakukan secara lengkap pada pencabangan pertama,kemudian selengkapnya pada pencabangan kedua, dan seterusnya secara rekursif.Algoritma diawali pada vertex S dalam G Kemudian algoritma menelusuri graph dengan suatu insiden edge (u,v) ke current vertex u. Jika edge (u, v) menunjuk ke suatu vertex v yang siap untuk dikunjungi, maka kita ikuti jalur mundur ke current vertex u. Jika pada sisi lain,edge (u, v) menunjuk ke vertex v yang tidak dikunjungi, maka kita pergi ke v dan v menjadi current vertex.[2]

2. BFS (Breadth First Search) Searching
Pada setiap pencabangan penelusuran verteks-verteks yang belum dikunjungi dilakukan pada verteks-verteks adjacent,kemudian berturut-turut selengkapnya pada masing-masing pencabangan dari setiap verteks adjacent tersebut secara rekursif.BFS diawali dengan vertex yang diberikan, yang mana di level 0. Dalam stage pertama, kita kunjungi semua vertex di level 1. Stage kedua, kita kunjungi semua vertex di level 2. Disini vertex baru, yang mana adjacent ke vertex level 1, dan seterusnya. Penelusuran BFS berakhir ketika setiap vertex selesai ditemui.[2]

3. Node dan Edge
Graf didefinisikan sebagai sekelompok simpulsimpul (nodes/vertices) V, dan sekelompok sisi(edges) E yang menghubungkan sepasang simpul.[3]

## Guided 

### 1. [Graph dengan beberapa fungsi]

```C++
//graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;      //menyimpan data node (misal: char/int)
    int visited;        //Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung
    adrNode Next;     //Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node;  //Pointer yang menunjuk ke lokasi node tujuan
    adrEdge Next;  //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang)
};

struct Graph {
    adrNode First;  //Pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G);  //prosedur untuk mengeset fitur dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data);  //alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);  //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data);  //menambahkan node ke dalam graph
adrNode FindNode(Graph G, infoGraph data);  //function untuk mencari alamat node berdasarkan nilai info yang diberikan
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua node (membuat edge dari info1 ke info2)
void DisconnectNode(adrNode node1, adrNode node2);  //prosedur untuk memutuskan hubungan dua node (menghapus edge dari node1 ke node2)
void DeleteNode(Graph &G, infoGraph X);  //prosedur untuk menghapus node X beserta semua Edge yang terhubung

void PrintInfoGraph(Graph G);  //Menampilkan isi graph(Adjency list)
void ResetVisited(Graph &G);  //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo);  //traversal Breadth Search / BFS (Menggunakan queue untuk menelusuri node berdasarkan tingkat)
void PrintDFS(Graph G, infoGraph StartInfo);  //traversal Depth First Search / DFS (menggunakan stack untuk menelusuri node secara mendalam)

#endif

//graph.cpp
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

//main.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    
    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak berhasil dihapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS

    return 0;
}
```
Kode di atas digunakan untuk mengimplementasikan graf tak berarah menggunakan adjacency list serta menampilkan hasil traversal BFS dan DFS ke layar dengan cout.

## Unguided 

### 1. [<img width="1330" height="1123" alt="Image" src="https://github.com/user-attachments/assets/e6b36025-a3e3-4ca6-9721-b8b22f8acc58" />]

```C++
//graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);

#endif


//graph.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void CreateGraph(graph &G){
    G.first = NULL;
}

void InsertNode(graph &G, infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;

    if(G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//main.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    //hubungkan antar node
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;
}
```
#### Output:
<img width="1582" height="242" alt="Image" src="https://github.com/user-attachments/assets/a90d7a2b-51bb-46b0-a2ca-980454e2c556" />

penjelasan unguided 1 Program ini berfungsi untuk membuat graph tak berarah (undirected graph) dengan menggunakan adjency list dalam menyimpan edge sebagai daftar hubungan dan menyimpan node dengan berupa karakter serta menampilkan hasil / hubungan antar node. Pada program ini, kita hanya menggunakan fungsi insertNode saja dalam menambahkan node ke dalam graph, tidak seperti guided yang menggunakan 2 fungsi. Kita menginisiasikan G.first sebagai NULL pada pembuatan graph kosong dan menampilkan hasil/outputnya dengan fungsi PrintInfoGraph.

#### Full code Screenshot:
<img width="1397" height="836" alt="Image" src="https://github.com/user-attachments/assets/ebf3ddf8-8035-4f04-b118-3ad781608f7e" />
 

### 2. [ Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintDFS (Graph G, adrNode N)]

```C++
//graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);
void PrintDFS(graph &G, adrNode N);

#endif


//graph.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void CreateGraph(graph &G){
    G.first = NULL;
}

void InsertNode(graph &G, infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;

    if(G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {

        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

void PrintDFS(graph &G, adrNode N){
    if (N == NULL) return;
    stack<adrNode> Stak;
    Stak.push(N);
    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

//main.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== Hasil Penelusuran DFS ===" << endl;
    PrintDFS(G, A);
    cout << endl;
}
```
#### Output:
<img width="1592" height="302" alt="Image" src="https://github.com/user-attachments/assets/bdece5a2-8350-42ac-80b1-f360b73766ae" />

penjelasan unguided 2 Program ini berfungsi untuk membuat graph tak berarah (undirected graph) dengan menggunakan adjency list dalam menyimpan edge sebagai daftar hubungan dan menyimpan node dengan berupa karakter serta menampilkan hasil / hubungan antar node. Pada program ini, program dapat melakukan penelusuran secara DFS dengan menggunakan stack. Dalam mereset visited, karena tidak menggunakan fungsi tambahan (fungsi resetVisited), kita perlu menginisiasi visited menjadi 0 dengan setiap node pada awalnya belum dikunjungi. Dalam menampilkan hasil dari penelusuran DFS ini, pada program ini kita memanggil fungsi PrintDFS dengan graph dan inisiasi awal yaitu A pada pemanggilan di kurung nya.

#### Full code Screenshot:
<img width="1191" height="938" alt="Image" src="https://github.com/user-attachments/assets/fa13b336-bdaa-450c-9e7b-2f3ae7bce5d4" />
 

### 3. [Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintBFS (Graph G, adrNode N)]

```C++
//graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);
void PrintDFS(graph &G, adrNode N);
void PrintBFS(graph &G, adrNode N);

#endif

//graph.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void CreateGraph(graph &G){
    G.first = NULL;
}

void InsertNode(graph &G, infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;

    if(G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {

        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

void PrintDFS(graph &G, adrNode N){
    adrNode temp = G.first;
    while (temp != NULL) {
        temp->visited = 0;
        temp = temp->Next;
    }
    if (N == NULL) return;
    stack<adrNode> Stak;
    Stak.push(N);
    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

void PrintBFS(graph &G, adrNode N){
    adrNode temp = G.first;
    while (temp != NULL) {
        temp->visited = 0;
        temp = temp->Next;
    }
    if (N == NULL ){
        return;
    }
    queue<adrNode> Qyu;
    Qyu.push(N);
    N->visited = 1;
    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//main.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
 
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== Hasil Penelusuran DFS ===" << endl;
    PrintDFS(G, A);
    cout << endl;

    cout << "=== Hasil Penelusuran BFS ===" << endl;
    PrintBFS(G, A);
    cout << endl;
}
```
#### Output:
<img width="1588" height="355" alt="Image" src="https://github.com/user-attachments/assets/b1675a68-5eea-4179-8eac-cf1ef8f50044" />

penjelasan unguided 3 Program ini berfungsi untuk membuat graph tak berarah (undirected graph) dengan menggunakan adjency list dalam menyimpan edge sebagai daftar hubungan dan menyimpan node dengan berupa karakter serta menampilkan hasil / hubungan antar node. Pada program ini, selain kita melakukan peneluran dengan menggunakan DFS (stack), kita menggunakan penelusuran dengan menggunakan metode BFS (queue). Karena tidak ada fungsi reset visited, kita menginisiasi visited dengan 0 pada awal fungsi. Untuk menampilkan output dalam penelusuran BFS, kita menginiasi fungsi tersebut dengan memanggil fungsi PrintBFS pada main program serta memanggil graph dan menginisiasi data awal (yaitu A) pada tanda kurung.

#### Full code Screenshot:
<img width="1326" height="968" alt="Image" src="https://github.com/user-attachments/assets/73677657-a021-4276-be7e-731d41b2b8cd" />

## Kesimpulan
Pada pembelajaran kali ini, kita akan dihadapkan dengan beberapa fungsi pada graph seperti Insertnode, Connectnode untuk menyambungkan 2 node, melakukan penelusuran node dengan menggunakan 2 fungsi yaitu secara DFS dan BFS. DFS sendiri merupakan pencarian penelusuran node dengan menggunakan fungsi stack, sedangkan BFS merupakan pencarian penelusuran node dengan menggunakan fungsi queue. Walau tanpa menggunakan fungsi alokasi dan findnode dalam melakukan insert dan tanpa menggunakan fungsi reset visited dalam melakukan pencarian secara DFS dan BFS, kita dapat menggunakan / memodifikasi pada fungsi insertNode agar dapat melakukan insert walau tanpa 2 fungsi tersebut (findNode dan alokasi) serta menginisiasi visited menjadi 0 dalam mereset visited pada awal fungsi DFS dan BFS serta dalam fungsi insertNode.

## Referensi
[1] MENGIDENTIFIKASI POLA KONSUMSI ENERGI RUMAH TANGGA MENGGUNAKAN ALGORITMA GRAFBERBASIS C++Alvin Hafiz, Fadilla Amanah, Revi Damurti, Putri HarlianaIlmu Komputer, Universitas Negeri Medan. Diakses pada tanggal 13 Desember 2025 melalui https://www.ejournal.itn.ac.id/jati/article/view/11788/6637. [2]Anita Sindar, R. M. S. (2019). Struktur Data Dan Algoritma Dengan C++ (Vol. 1). CV. AA. RIZKY. Diakses pada tanggal 13 Desember 2025 melalui https://www.researchgate.net/profile/Anita-Sindar/publication/337657500_STRUKTUR_DATA_DAN_ALGORITMA_DENGAN_C/links/5de3c560299bf10bc33628a2/STRUKTUR-DATA-DAN-ALGORITMA-DENGAN-C.pdf#page=19.26. [3]PENERAPAN GRAF UNTUK STRUKTUR DATA HIMPUNAN SALING LEPAS. Diakses pada tanggal 13 Desember 2025 melalui https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2006-2007/Makalah/Makalah0607-79.pdf.