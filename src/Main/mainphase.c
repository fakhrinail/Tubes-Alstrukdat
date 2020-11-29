#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Tree/tree.h"
#include "../PrioQueue/prioqueuechar.h"
#include "../Matriks/matriks.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"

void GeneratePengunjung(MATRIKS M, PrioQueueChar *Q)
{
    MakeEmpty(Q, 5); //5 jml maks pengunjung
    
    srand(time(0));
    int jmlpengunjung;
    jmlpengunjung = rand() % 6; //random antara 0-5
    while (jmlpengunjung == 0) //ulang kalo 0
    {
        jmlpengunjung = rand() % 6;
    }

    int totalwahana;
    int i = 0;
    while (!(isNil(M.arrayWahana[i].lokasi)))
    {
        totalwahana++;
    }
    
    int jmlwahana; //jml wahana yg ingin dikunjungi
    int j = 0;
    for (int i = 0; i < jmlpengunjung; i++)
    {
        jmlwahana = rand() % totalwahana+1;
        Enqueue(&Q, );
    }
}

void Serve(MATRIKS M, PrioQueueChar *Q)
{
    printf("Masukkan nama wahana yang ingin dilayani: ");
    ADVKATAi();
    if (isSame('bombomcar', CKataI))
    {
        
    }
    else if (isSame('halilintar', CKataI))
    {
        
    }
    else if (isSame('kora-kora', CKataI))
    {
        
    }
    else
    {
        printf("Tidak ada wahana dengan nama tersebut\n");
    }
}


void REPAIR();
void DETAIL();
void OFFICE(AddressTree T , MATRIKS Map){
    if(EQPoint(Map.Office,Player(Map))){
        printf(".-=~=-.                                      .-=~=-.\n");
        printf("(__  _)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(__  _)\n");
        printf("( _ __)                                      ( _ __)\n");
        printf("( _ __)               OFFICE                 ( _ __)\n");
        printf("( _ __)                                      ( _ __)\n");
        printf("(__  _)               1. Details             (__  _)\n");
        printf("(_ ___)                                      (_ ___)\n");
        printf("(__  _)               2. Report              (__  _)\n");
        printf("(__  _)                                      (__  _)\n");
        printf("( _ __)               3. Exit                ( _ __)\n");
        printf("(__  _)                                      (__  _)\n");
        printf("(_ ___)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(_ ___)\n");
        printf("`-._.-'                                      `-._.-'\n");
        printf("Masukkan perintah (1/2/3) : ");
        int input;
        scanf(input);
        if(input==1){
            detailsoffice(T);
        }
        else if(input==2){
            reportoffice(T);
        }
        else if(input==3){
            printf(" ___  ____  ____    _  _  _____  __  __ \n");
            printf("/ __)( ___)( ___)  ( \\/ )(  _  )(  )(  )\n");
            printf("\\__ \\ )__)  )__)    \\  /  )(_)(  )(__)( \n");
            printf("(___/(____)(____)   (__) (_____)(______)\n");
        }
        else{
            printf("Inputan anda salah!!");
        }
    }
}
void PREPARE(PrioQueueChar *Q){
    infotype *X;
    while(!IsEmpty(*Q)){
        Dequeue(&Q,X);
    }
    DeAlokasi(&Q);
    //panggil preparation phase disini
}

void detailsoffice(AddressTree T){
    printf(".-=~=-.                                      .-=~=-.\n");
    printf("(__  _)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(__  _)\n");
    printf("( _ __)       Details Nama-nama Wahana       ( _ __)\n");
    printf("( _ __)            1. bombomcar              ( _ __)\n");
    printf("( _ __)            2. halilintar             ( _ __)\n");
    printf("(__  _)            3. kora-kora              (__  _)\n");
    printf("(_ ___)            4.                        (_ ___)\n");
    printf("(__  _)            5.                        (__  _)\n");
    printf("(__  _)            6.                        (__  _)\n");
    printf("( _ __)            7.                        ( _ __)\n");
    printf("(_ ___)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(_ ___)\n");
    printf("`-._.-'                                      `-._.-'\n");
    printf("Masukkan perintah (1-7) : ");
    int input;
    scanf(input);

    if(input==1){
        AddressTree temp;
        temp = searchTree("bombomcar",T);
        printf("Nama        : %c\n",temp->detail.nama);
        printf("Harga       : %d\n",temp->detail.hargaTiket);
        printf("Lokasi      : \n");
        int i = 0;
        while(!isNil (temp->detail.lokasi[i])){
            TulisPOINT(temp->detail.lokasi[i]); printf(" ");
            i++;
        }
        printf("Deskripsi   : %c\n",temp->detail.deskripsi);
        printf("Kapasitas   : %d\n",temp->detail.kapasitas);
        printf("Durasi      : %d\n",temp->detail.durasi);
    }
    else if(input==2){
        AddressTree temp;
        temp = searchTree("halilintar",T);
        printf("Nama        : %c\n",temp->detail.nama);
        printf("Harga       : %d\n",temp->detail.hargaTiket);
        printf("Lokasi      : \n");
        int i = 0;
        while(!isNil (temp->detail.lokasi[i])){
            TulisPOINT(temp->detail.lokasi[i]); printf(" ");
            i++;
        }
        printf("Deskripsi   : %c\n",temp->detail.deskripsi);
        printf("Kapasitas   : %d\n",temp->detail.kapasitas);
        printf("Durasi      : %d\n",temp->detail.durasi);
    }
    else if(input==3){
        AddressTree temp;
        temp = searchTree("kora-kora",T);
        printf("Nama        : %c\n",temp->detail.nama);
        printf("Harga       : %d\n",temp->detail.hargaTiket);
        printf("Lokasi      : \n");
        int i = 0;
        while(!isNil (temp->detail.lokasi[i])){
            TulisPOINT(temp->detail.lokasi[i]); printf(" ");
            i++;
        }
        printf("Deskripsi   : %c\n",temp->detail.deskripsi);
        printf("Kapasitas   : %d\n",temp->detail.kapasitas);
        printf("Durasi      : %d\n",temp->detail.durasi);
    }
    else{
        printf("Inputan anda salah!!");
    }
}

void reportoffice(AddressTree T){
    printf(".-=~=-.                                      .-=~=-.\n");
    printf("(__  _)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(__  _)\n");
    printf("( _ __)      Report Nama-nama Wahana         ( _ __)\n");
    printf("( _ __)            1. bombomcar              ( _ __)\n");
    printf("( _ __)            2. halilintar             ( _ __)\n");
    printf("(__  _)            3. kora-kora              (__  _)\n");
    printf("(_ ___)            4.                        (_ ___)\n");
    printf("(__  _)            5.                        (__  _)\n");
    printf("(__  _)            6.                        (__  _)\n");
    printf("( _ __)            7.                        ( _ __)\n");
    printf("(_ ___)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(_ ___)\n");
    printf("`-._.-'                                      `-._.-'\n");
    printf("Masukkan perintah (1-7) : ");
    int input;
    scanf(input);

    if(input==1){
        AddressTree temp;
        temp = searchTree("bombomcar",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else if(input==2){
        AddressTree temp;
        temp = searchTree("halilintar",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else if(input==3){
        AddressTree temp;
        temp = searchTree("kora-kora",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else{
        printf("Inputan anda salah!!");
    }
}