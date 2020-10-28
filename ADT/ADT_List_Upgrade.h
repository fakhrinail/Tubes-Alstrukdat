
#ifndef list_upgrade_H
#define list_upgrade_H



typedef Eltype;
typedef Node* Address;
typedef struct {
    Eltype Aksi;
    char Wahana[20];
    Address Next;
} Node;

typedef struct{
    Address TOP;
} Stack;


#define Top(S) (S).TOP
#define AksiTop(S) (S).TOP->Aksi
#define WahanaTop(S) (S).TOP->Wahana
#define Next(S) (S).TOP->Next;
#define kosong NULL

void CreateEmpty(Stack *S);
/*
    Membuat stack kosong dengan TOP menunjuk kosong
*/

void Alokasi();
/*
    Mengalokasikan sebuah node ke memori
*/

void Dealokasi();
/*
    Mengdealokasikan memori sebesar sebuah node
*/

void Pop();
/*
    Mengeluarkan elemen paling atas dari stack, TOP menunjuk elemen sebelum TOP yang lama
*/

void Push();
/*
    Memberikan elemen baru ke dalam stack, TOP menunjuk elemen baru dan Next dari elemen baru adalah Next dari TOP yang lama
*/

#endif