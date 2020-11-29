#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Tree/tree.h"
#include "../Stack/stacklist.h"
#include "../PrioQueue/prioqueuechar.h"
#include "../Matriks/matriks.h"
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"


void reportoffice(AddressTree T); //pengganti .h biar ga implicit declaration
void detailsoffice(AddressTree T); //pengganti .h biar ga implicit declaration

/* dipanggil di awal mainphase */
void GeneratePengunjung(MATRIKS M, PrioQueueChar *Q)
{
    MakeEmpty(Q, 5); //5 jml maks pengunjung
    
    /* random jml pengunjung */
    srand(time(0));
    int jmlpengunjung;
    /* rand() % (max_number + 1 - minimum_number) + minimum_number */
    jmlpengunjung = rand() % (5+1-1) + 1; //random antara 1-5

    /* itung total wahana */
    int totalwahana;
    int i = 0;
    while (!(isNil(M.arrayWahana[i].lokasi)))
    {
        totalwahana++;
        i++;
    }
    
    for (int i = 0; i < jmlpengunjung; i++)
    {
        /* ngitung jml wahana yg bakal dikunjungi per pengunjung */
        int jmlwahana; //jml wahana yg ingin dikunjungi
        /* rand() % (max_number + 1 - minimum_number) + minimum_number */
        jmlwahana = rand() % (totalwahana+1-1) + 1; //jmlwahana antar 1-totalwahana
        
        /* isi daftar wahana tiap pengunjung */
        infotypeQ daftar;
        List listwahana;
        daftar.prio = i+1; //prioritas antrian
        daftar.sabar = 5; //kalo 0 bakal keluar queue
        daftar.daftarwahana; //listwahana yg ingin dikunjungi
        char namawahana[20];
        CopyString(&namawahana[20], M.arrayWahana[0].namaWahana);
        InsVLast(&daftar.daftarwahana, &namawahana[20]);

        /* kalau jml wahana lebih dari 1 */
        for (int j = 1; j < jmlwahana; j++)
        {
            CopyString(&namawahana[20], M.arrayWahana[1].namaWahana);
            InsVLast(&daftar.daftarwahana, &namawahana[20]);
        }
        
        /* tambah queue */
        Enqueue(Q, daftar);
    }
}

/* dipanggil kalo input command serve */
void Serve(MATRIKS* M, PrioQueueChar *Q)
{
    printf("Masukkan nama wahana yang ingin dilayani: ");
    ADVKATAi();
    //nanti dibuat fungsi rusak secara random tiap mau serve sesuatu wahana
    
    if (isSame(CKataI, "bombomcar"))
    {
        boolean cond = false;
        while (cond == false ){
            int i = 0;
            if (isSame((*M).arrayWahana[i].namaWahana,"bombomcar")){
                BreakWahana(M,"bombomcar");
                cond = true;
            }else{
                i++;
            }
            if (cond){
                if ((*M).arrayWahana[i].kondisi){
                    
                }

            }
        }
    }
    else if (isSame(CKataI, "halilintar"))
    {
        boolean cond = false;
        while (cond == false ){
            int i = 0;
            if (isSame((*M).arrayWahana[i].namaWahana,"halilintar")){
                BreakWahana(M,"halilintar");
                cond = true;
            }else{
                i++;
            }
        }
    }
    else if (isSame(CKataI, "kora-kora"))
    {
        boolean cond = false;
        while (cond == false ){
            int i = 0;
            if (isSame((*M).arrayWahana[i].namaWahana,"kora-kora")){
                BreakWahana(M,"kora-kora");
                cond = true;
            }else{
                i++;
            }
        }
    }
    else if (isSame(CKataI, "jungkat-jungkit"))
    {
        boolean cond = false;
        while (cond == false ){
            int i = 0;
            if (isSame((*M).arrayWahana[i].namaWahana,"jungkat-jungkit")){
                BreakWahana(M,"jungkat-jungkit");
                cond = true;
            }else{
                i++;
            }
        }
    }
    else if (isSame(CKataI, "rollercoaster"))
    {
        boolean cond = false;
        while (cond == false ){
            int i = 0;
            if (isSame((*M).arrayWahana[i].namaWahana,"rollercoaster")){
                BreakWahana(M,"rollercoaster");
                cond = true;
            }else{
                i++;
            }
        }
    }
    else if (isSame(CKataI, "rollercoaster"))
    {
        boolean cond = false;
        while (cond == false ){
            int i = 0;
            if (isSame((*M).arrayWahana[i].namaWahana,"rollercoaster")){
                BreakWahana(M,"rollercoaster");
                cond = true;
            }else{
                i++;
            }
        }
    }
    else if (isSame(CKataI, "bianglala"))
    {
        boolean cond = false;
        while (cond == false ){
            int i = 0;
            if (isSame((*M).arrayWahana[i].namaWahana,"bianglala")){
                BreakWahana(M,"bianglala");
                cond = true;
            }else{
                i++;
            }
        }
    }
    else if (isSame(CKataI, "tornado"))
    {
        boolean cond = false;
        while (cond == false ){
            int i = 0;
            if (isSame((*M).arrayWahana[i].namaWahana,"tornado")){
                BreakWahana(M,"tornado");
                cond = true;
            }else{
                i++;
            }
        }
    }
    else
    {
        printf("Tidak ada wahana dengan nama tersebut\n");
    }
}


/* dipanggil setiap mau serve wahana tersebut */
void BreakWahana (MATRIKS *M, char namawahana[])
{
    srand(time(0));
    /* rand() % (max_number + 1 - minimum_number) + minimum_number */
    int rusak = rand() % (4+1-1) + 1;
    /* peluang rusak 1/4 */
    if (rusak == 1) //kalo 1 rusak
    {
        int i = 0;
        /* ubah setiap wahana dengan nama sama jadi rusak */
        while (!(isNil(M->arrayWahana[i].lokasi)))
        {
            if (isSame(M->arrayWahana[i].namaWahana, namawahana))
            {
                M->arrayWahana[i].kondisi = false; //set ke rusak
            }
        }
    }
}

void REPAIR(MATRIKS *M)
{
    if (!(isNil(cekWahana(*M)))) //cek di sebelah wahana atau ga
    {
        POINT wahana = cekWahana(*M);
        int i;
        while (EQPoint(M->arrayWahana[i].lokasi, wahana)) //cari wahana sesuai lokasi
        {
            i++;
        }
        M->arrayWahana[i].kondisi = true;
    }
}

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
        scanf("%d", &input); //ganti pake mesin kata
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
void DETAIL(MATRIKS M){
    POINT asu = MakePOINT(-1,-1);
    POINT cek = cekWahana(M);
    boolean cond = false;
    if (NEQPoint(asu,cek)){
        while(cond == false){
            int i = 0;
            if (EQPoint(cek,M.arrayWahana[i].lokasi)){
                printf("Nama wahana                 : %d\n",M.arrayWahana[i].namaWahana);
                printf("Harga wahana                : %d\n",M.arrayWahana[i].hargawahana);
                printf("Lokasi wahana               : %d\n",M.arrayWahana[i].lokasi);
                printf("Kondisi                     : %d\n",M.arrayWahana[i].kondisi);
                printf("Riwayat upgrade wahana      : %d\n",M.arrayWahana[i].historyUpgrade);
                printf("Upgrade 1                   : %d\n",M.arrayWahana[i].upgrade1);
                printf("Upgrade 2                   : %d\n",M.arrayWahana[i].upgrade2);
                cond = true;
            }
            i++;
        }
    }
}

void PREPARE(PrioQueueChar *Q){
    infotypeQ *X;
    while(!IsEmpty(*Q)){
        Dequeue(Q,X);
    }
    DeAlokasi(Q);
    //panggil preparation phase disini
}

void reportoffice(AddressTree T){
    printf(".-=~=-.                                      .-=~=-.\n");
    printf("(__  _)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(__  _)\n");
    printf("( _ __)       Report Nama-nama Wahana        ( _ __)\n");
    printf("( _ __)            1. bombomcar              ( _ __)\n");
    printf("( _ __)            2. halilintar             ( _ __)\n");
    printf("(__  _)            3. kora-kora              (__  _)\n");
    printf("(_ ___)            4. jungkat-jungkit        (_ ___)\n");
    printf("(__  _)            5. rollercoaster          (__  _)\n");
    printf("(__  _)            6. bianglala              (__  _)\n");
    printf("( _ __)            7. tornado                ( _ __)\n");
    printf("(_ ___)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(_ ___)\n");
    printf("`-._.-'                                      `-._.-'\n");
    printf("Masukkan perintah (1-7) : ");
    ADVKATAi();

    if(StrToInt(CKataI)==1){
        AddressTree temp;
        temp = searchTree("bombomcar",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else if(StrToInt(CKataI)==2){
        AddressTree temp;
        temp = searchTree("halilintar",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else if(StrToInt(CKataI)==3){
        AddressTree temp;
        temp = searchTree("kora-kora",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else if(StrToInt(CKataI)==4){
        AddressTree temp;
        temp = searchTree("jungkat-jungkit",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else if(StrToInt(CKataI)==5){
        AddressTree temp;
        temp = searchTree("rollercoaster",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else if(StrToInt(CKataI)==6){
        AddressTree temp;
        temp = searchTree("bianglala",T);
        printf("Nama                : %c\n",temp->detail.nama);
        printf("Total Pengunjung    : %d\n",temp->detail.totalDinaiki);
        printf("Total Penghasilan   : %d\n",temp->detail.totalPenghasilan);
        printf("Pengunjung 1 hari   : %d\n",temp->detail.oneDayDinaiki);
        printf("Penghasilan 1 hari  : %d\n",temp->detail.oneDayPenghasilan);
    }
    else if(StrToInt(CKataI)==7){
        AddressTree temp;
        temp = searchTree("tornado",T);
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

void detailsoffice(AddressTree T){
    printf(".-=~=-.                                      .-=~=-.\n");
    printf("(__  _)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(__  _)\n");
    printf("( _ __)       Details Nama-nama Wahana       ( _ __)\n");
    printf("( _ __)            1. bombomcar              ( _ __)\n");
    printf("( _ __)            2. halilintar             ( _ __)\n");
    printf("(__  _)            3. kora-kora              (__  _)\n");
    printf("(_ ___)            4. jungkat-jungkit        (_ ___)\n");
    printf("(__  _)            5. rollercoaster          (__  _)\n");
    printf("(__  _)            6. bianglala              (__  _)\n");
    printf("( _ __)            7. tornado                ( _ __)\n");
    printf("(_ ___)-._.-=-._.-=-._.-=--=-._.-=-._.-=-._.-(_ ___)\n");
    printf("`-._.-'                                      `-._.-'\n");
    printf("Masukkan perintah (1-7) : ");
    ADVKATAi();

    if(StrToInt(CKataI)==1){
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
    else if(StrToInt(CKataI)==2){
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
    else if(StrToInt(CKataI)==3){
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
    else if(StrToInt(CKataI)==4){
        AddressTree temp;
        temp = searchTree("jungkat-jungkit",T);
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
    else if(StrToInt(CKataI)==5){
        AddressTree temp;
        temp = searchTree("rollercoaster",T);
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
    else if(StrToInt(CKataI)==6){
        AddressTree temp;
        temp = searchTree("bianglala",T);
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
    else if(StrToInt(CKataI)==3){
        AddressTree temp;
        temp = searchTree("tornado",T);
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