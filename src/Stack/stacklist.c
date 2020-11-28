/* 
Nama/NIM : Fakhri Nail Wibowo/13519035
Tanggal : 21-11-2020
Topik : Variasi list linier
Deskripsi : Realisasi stacklist.h
*/

#include "stacklist.h"
#include "boolean.h"
#include <stdlib.h>

/* Prototype manajemen memori */
addressStack AlokasiStack (infotype cmd, infotype uang, infotype jml[], infotype waktu, POINT lokasi, char namaWahana[])
/* Ini parameternya bakal diisi lewat buy, build, atau upgrade, nanti liat dee */
{
    addressStack P = malloc(sizeof(ElmtStack));
    if (P != NULL)
    {
        Command(P) = cmd;
        Uang(P) = uang;
        P->kayu = jml[0];
        P->batu = jml[1];
        P->metal = jml[2];
        Waktu(P) = waktu;
        P->lokasi.baris = Baris(lokasi);
        P->lokasi.kolom = Kolom(lokasi);
        CopyString(P->namaWahana,namaWahana);
        Next(P) = NULL;
    }
    return P;
}
void DealokasiStack (addressStack P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 
{
    free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
    return Top(S) == NULL;
}
void CreateEmptyStackList (Stack * S)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
{
    Top(*S) = NULL;
}
void Push (Stack * S, addressStack P)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
    if (IsEmpty(*S)){
        Next(P) = NULL;
        (*S).TOP = P;
    }else{
        Next(P) = Next((*S).TOP);
        (*S).TOP = P;
    }
}
/* TODO FIX-IN POP */
void Pop (Stack* S, int* uangPengguna, JAM* jamPengguna, int bahanPengguna[], MATRIKS* Map)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
    if (InfoCommandTop(*S)==1){
        *uangPengguna -= InfoUangTop(*S);
        int HH = InfoWaktuTop(*S)/60;
        int MM = InfoWaktuTop(*S)%60;
        (*jamPengguna).HH += HH;
        (*jamPengguna).MM += MM;
        bahanPengguna[0] -= InfoKayuTop(*S);
        bahanPengguna[1] -= InfoBatuTop(*S);
        bahanPengguna[2] -= InfoMetalTop(*S);
        
        /* Mencari lokasi yang masih kosong */
        int i=0;
        while (!isNil((*Map).arrayWahana[i].lokasi)){
            i++;
        }
        (*Map).arrayWahana[i].lokasi = InfoLokasiTop(*S);
        CopyString((*Map).arrayWahana[i].namaWahana,(*S).TOP->namaWahana);

    }else if (InfoCommandTop(*S)==2){
        *uangPengguna -= InfoUangTop(*S);
        int HH = InfoWaktuTop(*S)/60;
        int MM = InfoWaktuTop(*S)%60;
        (*jamPengguna).HH += HH;
        (*jamPengguna).MM += MM;
        bahanPengguna[0] -= InfoKayuTop(*S);
        bahanPengguna[1] -= InfoBatuTop(*S);
        bahanPengguna[2] -= InfoMetalTop(*S);
        
        /* Mencari lokasi*/
        int i=0;
        while (!isNil((*Map).arrayWahana[i].lokasi)){
            if ( Baris((*Map).arrayWahana[i].lokasi) == Baris((*Map).Player) && Kolom((*Map).arrayWahana[i].lokasi) == Kolom((*Map).Player)){
                (*Map).arrayWahana[i].lokasi = InfoLokasiTop(*S);
                break;
            }
            else{
                i++;
            }
        }
    }
    else if (InfoCommandTop(*S)==3){
        *uangPengguna -= InfoUangTop(*S);
        int HH = InfoWaktuTop(*S)/60;
        int MM = InfoWaktuTop(*S)%60;
        (*jamPengguna).HH += HH;
        (*jamPengguna).MM += MM;
        bahanPengguna[0] -= InfoKayuTop(*S);
        bahanPengguna[1] -= InfoBatuTop(*S);
        bahanPengguna[2] -= InfoMetalTop(*S);
        
    }
}

void Buy(Stack *S, BahanBangunan listbahan[], int uangPengguna, JAM waktu)
{
    /* Menghitung Waktu */
    int totalWaktu = 0;
    if (!IsEmpty(*S)){
        addressStack P = (*S).TOP;
        while (Next(P)!=NULL){
            totalWaktu += P->waktu;
            P = Next(P);
        }
        totalWaktu += P->waktu;
    }

    /* Menghitung waktu sekarang */
    int currentJam = 0;
    if (JAMToMenit(waktu)<JAMToMenit(MakeJAM(21,0))){
        currentJam = JAMToMenit(MakeJAM(24,0)) - JAMToMenit(MakeJAM(21,0)) + JAMToMenit(waktu);
    }else{
        currentJam = JAMToMenit(waktu) - JAMToMenit(MakeJAM(21,0));
    }

    /* Menghitung uang yang telah di-spend dalam beberapa aksi */
    int totalUang = 0;
    if (!IsEmpty(*S)){
        addressStack P = (*S).TOP;
        while (Next(P)!=NULL){
            totalUang += P->uang;
            P = Next(P);
        }
        totalUang += P->uang;
    }

    /* Menentukan apakah waktu cukup atau tidak, buy menghabiskan waktu 30 menit  */
    if (totalWaktu+currentJam+30 > 720){                   //lebih dari 12 jam
        printf("Oops, waktu melebih batas!\n");
    }else{
        /* Memulai pesanan */

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

        if (jmlharga + totalUang > uangPengguna){
            printf("Uang Anda tidak mencukupi\n");
        }
        else{
            /* Membuat array of bahan */
            infotype bahan[3];
            for (int i=0;i<3;i++){
                if (i==pilihan-1){
                    bahan[i] = jml;
                }else{
                    bahan[i] = 0;
                }
            }
            
            /* Membuat dummy dummy*/
            char dummy[20];
            MakeString20Empty(dummy);

            /* ALOKASI */
            addressStack varBuy = AlokasiStack(3,jmlharga,bahan,30,MakePOINT(-1,-1),dummy);
            if (varBuy!=NULL){
                Push(S, varBuy);
                printf("Pembelian anda tercatat, Terima kasih!\n");
            }else{
                printf("Oops, Terjadi error dalam program\n");
            }
        }
    }
}

void Build(Stack *S, int bahanPengguna[], int uangPengguna, JAM waktu, AddressTree T, POINT posisiPlayer)
{
    /* Menghitung Waktu */
    int totalWaktu = 0;
    if (!IsEmpty(*S)){
        addressStack P = (*S).TOP;
        while (Next(P)!=NULL){
            totalWaktu += P->waktu;
            P = Next(P);
        }
        totalWaktu += P->waktu;
    }

    /* Menghitung waktu sekarang */
    int currentJam = 0;
    if (JAMToMenit(waktu)<JAMToMenit(MakeJAM(21,0))){
        currentJam = JAMToMenit(MakeJAM(24,0)) - JAMToMenit(MakeJAM(21,0)) + JAMToMenit(waktu);
    }else{
        currentJam = JAMToMenit(waktu) - JAMToMenit(MakeJAM(21,0));
    }

    /* Menghitung uang yang telah di-spend dalam beberapa aksi */
    int totalUang = 0;
    if (!IsEmpty(*S)){
        addressStack P = (*S).TOP;
        while (Next(P)!=NULL){
            totalUang += P->uang;
            P = Next(P);
        }
        totalUang += P->uang;
    }

    /* Menentukan apakah waktu cukup atau tidak, build menghabiskan waktu 120 menit */
    if (totalWaktu+currentJam+120 > 720){
        printf("Oops, waktu melebihi batas!\n");
    }else{
        printf("Berikut wahana yang bisa anda bangun: \n");
        printf("    -%s\n", NamaWahana(T));
        ADVKATAi();
        while (!isSame(NamaWahana(T),CKataI)){
            printf("Oops, inputan anda tidak valid. Silahkan ulangi\n");
            ADVKATAi();
        }
        if (uangPengguna>=HargaBangun(T)+totalUang && (bahanPengguna[0]>=KayuBangun(T) && bahanPengguna[1]>= BatuBangun(T) && bahanPengguna[2]>=MetalBangun(T))){
            addressStack VarBuild = AlokasiStack(1,HargaBangun(T),T->detail.bahanBangun,120,posisiPlayer,NamaWahana(T));
            if (VarBuild!=NULL){
                Push(S, VarBuild);
                printf("Aksi Build anda tercatat, Terima kasih!\n");
            }else{
                printf("Oops, Terjadi error pada sistem hubungi teknisi untuk memperbaiki\n");
            }
        }else{
            printf("Oops, uang atau bahan anda tidak mencukupi untuk melakukan aksi ini.\n");
        }
    }
}

void Upgrade(Stack *S, int bahanPengguna[], int uangPengguna, JAM waktu, AddressTree T, POINT posisiPlayer)
{
    /* Menghitung Waktu */
    int totalWaktu = 0;
    if (!IsEmpty(*S)){
        addressStack P = (*S).TOP;
        while (Next(P)!=NULL){
            totalWaktu += P->waktu;
            P = Next(P);
        }
        totalWaktu += P->waktu;
    }

    /* Menghitung waktu sekarang */
    int currentJam = 0;
    if (JAMToMenit(waktu)<JAMToMenit(MakeJAM(21,0))){
        currentJam = JAMToMenit(MakeJAM(24,0)) - JAMToMenit(MakeJAM(21,0)) + JAMToMenit(waktu);
    }else{
        currentJam = JAMToMenit(waktu) - JAMToMenit(MakeJAM(21,0));
    }

    /* Menghitung uang yang telah di-spend dalam beberapa aksi */
    int totalUang = 0;
    if (!IsEmpty(*S)){
        addressStack P = (*S).TOP;
        while (Next(P)!=NULL){
            totalUang += P->uang;
            P = Next(P);
        }
        totalUang += P->uang;
    }

    /* Menentukan apakah waktu cukup atau tidak, build menghabiskan waktu 120 menit */
    if(cekwahana){
        if (totalWaktu+currentJam+120 > 720){
            printf("Oops, waktu melebihi batas!\n");
        }
        else{
            printf("Berikut wahana yang bisa anda upgrade: \n");
            printf("1. Halilintar");
            printf("2. Kora Kora");
            int input;
            scanf(input);
            if(input == 1){
                 if (uangPengguna>=T->Left->detail.hargaBangun + totalUang && (bahanPengguna[0]>= T->Left->detail.bahanBangun[0] && bahanPengguna[1]>= T->Left->detail.bahanBangun[1] && bahanPengguna[2]>=T->Left->detail.bahanBangun[2])){
                    addressStack VarUpgrade = AlokasiStack(2,T->Left->detail.hargaBangun,T->Left->detail.bahanBangun,120, posisiPlayer, T->Left->detail.nama);
                    if (VarUpgrade!=NULL){
                        Push(S, VarUpgrade);
                        printf("Aksi Upgrade anda tercatat, Terima kasih!\n");
                    }else{
                        printf("Oops, Terjadi error pada sistem hubungi teknisi untuk memperbaiki\n");
                    }
                }else{
                    printf("Oops, uang atau bahan anda tidak mencukupi untuk melakukan aksi ini.\n");
                }
            }
            if(input == 2){
                 if (uangPengguna>=T->Right->detail.hargaBangun + totalUang && (bahanPengguna[0]>= T->Right->detail.bahanBangun[0] && bahanPengguna[1]>= T->Right->detail.bahanBangun[1] && bahanPengguna[2]>=T->Right->detail.bahanBangun[2])){
                    addressStack VarUpgrade = AlokasiStack(2,T->Right->detail.hargaBangun,T->Right->detail.bahanBangun,120, posisiPlayer, T->Right->detail.nama);
                    if (VarUpgrade!=NULL){
                        Push(S, VarUpgrade);
                        printf("Aksi Upgrade anda tercatat, Terima kasih!\n");
                    }else{
                        printf("Oops, Terjadi error pada sistem hubungi teknisi untuk memperbaiki\n");
                    }
                }else{
                    printf("Oops, uang atau bahan anda tidak mencukupi untuk melakukan aksi ini.\n");
                }
            }
        }
    }
    else{
        printf("Oopss, anda tidak berdiri di wahana apa-apa");
    }
}

boolean cekwahana(MATRIKS Map){
    boolean cek = false;
    for (int i=0; i<30;i++){
        if ( Baris(Map.arrayWahana[i].lokasi) == Baris(Map.Player) && Kolom(Map.arrayWahana[i].lokasi) == Kolom(Map.Player)){
            cek = true;
        }       
    } 
    return cek;
}