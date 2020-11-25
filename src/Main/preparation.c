#include <stdio.h>
#include <stdlib.h>
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include "../Point/point.h"
#include "../Tree/tree.h"
#include "../Jam/jam.h"
#include "../Matriks/matriks.h"
#include "preparation.h"


/* Buy */
void DaftarBahan(BahanBangunan listbahan[])
{
    int i = 0;
    STARTKATAf("../../doc/material.txt");
    while (!EndFile)
    {
        while (!EndLine)
        {
            CopyString(listbahan[i].namabahan,CKataF);
            ADVKATAf();
            listbahan[i].hargabahan = StrToInt(CKataF);
        }
        ADVKATAf();     //maju ke line di bawahnya
        i++;
    }
}

VarBuy* Buy(BahanBangunan listbahan[], int uangPengguna, JAM waktu)
{
    JAM acuan = MakeJAM(9,0);
    int temp = JAMToMenit(waktu);
    temp += 30;            //buy menghabiskan waktu setengah jam
    waktu = MenitToJAM(temp);

    if ((waktu.HH > acuan.HH && waktu.HH >= 21) || waktu.HH < acuan.HH){        //waktunya cukup untuk melakukan buy
        int pilihan;
        int jml;

        printf("Berikut adalah list bahan yang bisa dibeli:\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d. %s %d\n", i+1, listbahan[i].namabahan, listbahan[i].hargabahan);
        }
        
        printf("Masukkan bahan yang ingin dibeli:\n ");
        ADVKATAi();
        pilihan = StrToInt(CKataI);
        printf("Masukkan jumlah yang ingin dibeli:\n ");
        ADVKATAi();
        jml = StrToInt(CKataI);
        
        int hargabahan = listbahan[pilihan-1].hargabahan;
        int jmlharga = jml*hargabahan;
        if (jmlharga > uangPengguna)
        {
            printf("Uang Anda tidak mencukupi\n");
            return NULL;
        }
        else
        {
            VarBuy* B = malloc(sizeof(VarBuy));
            B->uang = jmlharga;
            B->jmlbahan[pilihan-1] = jml;
            printf("Pembelian Anda tercatat, terima kasih sudah membeli!\n");
            return B;
        }
        
    }else if (waktu.HH > acuan.HH && waktu.HH <21){
        printf("Oops, waktu yang dibutuhkan sudah melebih batas. \n");
        return NULL;
    }
}

/* Build */
VarBuild* Build(AddressTree T, int uangPengguna, int bahanBangunanPengguna[], JAM waktu, MATRIKS MAP)
{
    JAM acuan = MakeJAM(9,0);
    int temp = JAMToMenit(waktu);
    temp += 120;            //build menghabiskan waktu 2 jam
    waktu = MenitToJAM(temp);

    if ((waktu.HH > acuan.HH && waktu.HH >= 21) || waktu.HH < acuan.HH){        //waktunya cukup untuk melakukan build
        printf("Berikut wahana yang bisa anda bangun: \n");
        printf("    -%s\n", NamaWahana(T));
        ADVKATAi();
        while (!isSame(NamaWahana(T),CKataI)){
            printf("Oops, inputan anda tidak valid. Silahkan ulangi\n");
            ADVKATAi();
        }
        if (uangPengguna>=HargaBangun(T) && (bahanBangunanPengguna[0]>=KayuBangun(T) && bahanBangunanPengguna[1]>= BatuBangun(T) && bahanBangunanPengguna[2]>=MetalBangun(T))){
            VarBuild* B = malloc(sizeof(VarBuild));
            CopyString(B->namaWahana,NamaWahana(T));
            B->bahanBangun[0] = bahanBangunanPengguna[0];
            B->bahanBangun[1] = bahanBangunanPengguna[1];
            B->bahanBangun[2] = bahanBangunanPengguna[2];
            B->hargaBangun = HargaBangun(T);
            B->lokasi =  MAP.Player;
            B->waktu = 120;
            printf("Aksi build anda tercatat.\n");
            return B;

        }else{
            printf("Oops, uang anda tidak mencukupi untuk melakukan aksi ini.\n");
            return NULL;
        }
    }else if (waktu.HH > acuan.HH && waktu.HH <21){
        printf("Oops, waktu yang dibutuhkan sudah melebih batas. \n");
        return NULL;
    }
}

/* Upgrade */

VarUpgrade* Upgrade(AddressTree T, int uangPengguna, int bahanBangunanPengguna[], JAM waktu, MATRIKS MAP)
{
    JAM acuan = MakeJAM(9,0);
    int temp = JAMToMenit(waktu);
    temp += 180;            //upgrade menghabiskan waktu 3 jam
    waktu = MenitToJAM(temp);

    if ((waktu.HH > acuan.HH && waktu.HH >= 21) || waktu.HH < acuan.HH){
        
    }else if (waktu.HH > acuan.HH && waktu.HH <21){

    }
}