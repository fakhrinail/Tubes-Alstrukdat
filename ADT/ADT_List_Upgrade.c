#include <stdlib.h>
#include "ADT_List_Upgrade.h"

void CreateEmpty(Stack *S)
/*
    Membuat stack kosong dengan TOP menunjuk kosong
*/
{
    Top(*S) = kosong;
}

Address Alokasi(Eltype aksi, char nama_wahana[20])
/*
    Mengalokasikan sebuah node ke memori
*/
{
    Address newNode = malloc(sizeof(Node));
    if (newNode==kosong){
        printf("Alokasi memori gagal.");
        return kosong;
    }else{
        newNode->Aksi = aksi;
        newNode->Wahana[20] = nama_wahana;
        newNode->Next = kosong;
        return newNode;
    }
}

void Dealokasi(Address alamat)
/*
    Mengdealokasikan memori sebesar sebuah node
*/
{
    if (alamat!=kosong){
        free(alamat);
    }
}

void Pop();
/*
    Mengeluarkan elemen paling atas dari stack, TOP menunjuk elemen sebelum TOP yang lama
*/

void Push();
/*
    Memberikan elemen baru ke dalam stack, TOP menunjuk elemen baru dan Next dari elemen baru adalah Next dari TOP yang lama
*/