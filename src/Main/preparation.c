#include <stdio.h>
#include <stdlib.h>
#include "../MesinKarakter-Kata/mesinkar.h"
#include "../MesinKarakter-Kata/mesinkarfile.h"
#include "../MesinKarakter-Kata/mesinkata.h"

BahanBangunan listbahan[3];

typedef struct 
{
    int uang;
    char jmlbahan[3];
} VarBuy;

typedef struct
{
    char namabahan[10];
    int hargabahan;
} BahanBangunan;

void DaftarBahan(BahanBangunan *listbahan)
{
    BahanBangunan bahan;
    int i = 0;
    STARTKATA();
    while (!(EndKata))
    {
        CopyString(listbahan[i].namabahan,CKata);
        listbahan[i].hargabahan = StrToInt(CKata);
        ADVKATA();
        i++;
    }
}

void Buy()
{
    VarBuy buy;
    int pilihan;
    int jml;

    printf("Berikut adalah list bahan yang bisa dibeli:\n");
    for (int i = 0; i < 3; i++)
    {
        char nama[] = listbahan[i].namabahan;
        int harga = listbahan[i].hargabahan;
        printf("%d. %s %d\n", i+1, nama, harga);
    }
    
    printf("Masukkan bahan yang ingin dibeli:\n ");
    STARTKATA();
    pilihan = StrToInt(CKata);
    STARTKATA();
    jml = StrToInt(CKata);
    
    int hargabahan = listbahan[pilihan-1].hargabahan;
    if (jml*hargabahan)
    {
        printf("Uang Anda tidak mencukupi\n");
    }
    else
    {
        //masukin ke stack pake VarBuy
    }
}