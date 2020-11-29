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
addressStack AlokasiStack (int cmd, int uang, int jml[], int waktu, POINT lokasi, char namaWahana[])
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
        P->Next = NULL;
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
boolean IsEmptyStack (Stack S)
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
    if (IsEmptyStack(*S)){
        P->Next = NULL;
        (*S).TOP = P;
    }else{
        P->Next = (*S).TOP->Next;
        (*S).TOP = P;
    }
}


void Pop (Stack* S, int* uangPengguna, JAM* jamPengguna, int bahanPengguna[], MATRIKS* Map, AddressTree* T)
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
        /* isi detail wahana */
        (*Map).arrayWahana[i].lokasi = InfoLokasiTop(*S);
        CopyString((*Map).arrayWahana[i].namaWahana,(*S).TOP->namaWahana);
        
        AddressTree P = searchTree((*S).TOP->namaWahana,(*T));
        (*Map).arrayWahana[i].hargawahana = P->detail.hargaTiket;
        (*Map).arrayWahana[i].historyUpgrade.First = NULL;
        (*Map).arrayWahana[i].kondisi = true;
        if (Left(P)!=NULL && Right(P)!=NULL){
            CopyString((*Map).arrayWahana[i].upgrade1, Left(P)->Left->detail.nama);
            CopyString((*Map).arrayWahana[i].upgrade2, Right(P)->Left->detail.nama);
        }else{
            MakeString20Empty((*Map).arrayWahana[i].upgrade1);
            MakeString20Empty((*Map).arrayWahana[i].upgrade2);
        }
        
        /* Dealokasi */
        addressStack Temp = (*S).TOP;
        (*S).TOP = (*S).TOP->Next;
        DealokasiStack(Temp);

    }else if (InfoCommandTop(*S)==2){
        *uangPengguna -= InfoUangTop(*S);
        int HH = InfoWaktuTop(*S)/60;
        int MM = InfoWaktuTop(*S)%60;
        (*jamPengguna).HH += HH;
        (*jamPengguna).MM += MM;
        bahanPengguna[0] -= InfoKayuTop(*S);
        bahanPengguna[1] -= InfoBatuTop(*S);
        bahanPengguna[2] -= InfoMetalTop(*S);
        
        /* Mencari lokasi dan mengupgradenya*/
        int i=0;
        boolean found = false;
        while (!isNil((*Map).arrayWahana[i].lokasi) && !found){
            if (EQPoint((*Map).arrayWahana[i].lokasi,(*S).TOP->lokasi)){
                found=true;
            }
            else{
                i++;
            }
        }
        /* isi detail wahana */
        AddressTree P = searchTree((*S).TOP->namaWahana,(*T));         //cari wahana yg sesuai

        (*Map).arrayWahana[i].hargawahana = P->detail.hargaTiket;
        InsVLast(&(*Map).arrayWahana[i].historyUpgrade, (*Map).arrayWahana[i].namaWahana);
        (*Map).arrayWahana[i].kondisi = true;
        if (Left(P)!=NULL && Right(P)!=NULL){
            CopyString((*Map).arrayWahana[i].upgrade1, Left(P)->Left->detail.nama);
            CopyString((*Map).arrayWahana[i].upgrade2, Right(P)->Left->detail.nama);
        }else{
            MakeString20Empty((*Map).arrayWahana[i].upgrade1);
            MakeString20Empty((*Map).arrayWahana[i].upgrade2);
        }
        CopyString((*Map).arrayWahana[i].namaWahana,(*S).TOP->namaWahana);

        /* Dealokasi */
        addressStack Temp = (*S).TOP;
        (*S).TOP = (*S).TOP->Next;
        DealokasiStack(Temp);

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
    if (!IsEmptyStack(*S)){
        addressStack P = (*S).TOP;
        while (P->Next!=NULL){
            totalWaktu += P->waktu;
            P = P->Next;
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
    if (!IsEmptyStack(*S)){
        addressStack P = (*S).TOP;
        while (P->Next!=NULL){
            totalUang += P->uang;
            P = P->Next;
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
            int bahan[3];
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
    if (!IsEmptyStack(*S)){
        addressStack P = (*S).TOP;
        while (P->Next!=NULL){
            totalWaktu += P->waktu;
            P = P->Next;
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
    if (!IsEmptyStack(*S)){
        addressStack P = (*S).TOP;
        while (P->Next!=NULL){
            totalUang += P->uang;
            P = P->Next;
        }
        totalUang += P->uang;
    }

    /* Menentukan apakah waktu cukup atau tidak, build menghabiskan waktu 120 menit */
    if (totalWaktu+currentJam+120 > 720){
        printf("Oops, waktu melebihi batas!\n");
    }else{
        printf("Berikut wahana yang bisa anda bangun: \n");
        printf("    - %s\n", NamaWahana(T));
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

void Upgrade(Stack *S, int bahanPengguna[], int uangPengguna, JAM waktu, AddressTree T, MATRIKS MAP)
{
    /* Menghitung Waktu */
    int totalWaktu = 0;
    if (!IsEmptyStack(*S)){
        addressStack P = (*S).TOP;
        while (P->Next!=NULL){
            totalWaktu += P->waktu;
            P = P->Next;
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
    if (!IsEmptyStack(*S)){
        addressStack P = (*S).TOP;
        while (P->Next!=NULL){
            totalUang += P->uang;
            P = P->Next;
        }
        totalUang += P->uang;
    }
    
    /* Menentukan apakah player berada di sebelah wahana atau tidak */

    if (!isNil(cekWahana(MAP))){

        /* Menentukan apakah waktu cukup atau tidak, upgrade menghabiskan waktu 120 menit */

        if (totalWaktu+currentJam+120 > 720){
            printf("Oops, waktu melebihi batas!\n");
        }
        else{

            /* menemukan wahana yang di sebelah player yang mana */
            POINT temp = cekWahana(MAP);
            int i=0;
            boolean found = false;

            while(!found){
                if (EQPoint(MAP.arrayWahana[i].lokasi, temp)){
                    found = true;
                }else{
                    i++;
                }
            }

            /* memberikan pilihan ke pengguna */
            AddressTree correctWahana = searchTree(MAP.arrayWahana[i].namaWahana,T);
            printf("Berikut wahana yang bisa anda upgrade: \n");
            printf("    1. %s",Left(correctWahana)->detail.nama);       //1 kiri
            printf("    2. %s",Right(correctWahana)->detail.nama);      //2 kanan

            int input;
            scanf("%d", &input);
            if(input == 1){
                 if (uangPengguna >= Left(correctWahana)->detail.hargaBangun + totalUang && bahanPengguna[0] >= Left(correctWahana)->detail.bahanBangun[0] && bahanPengguna[1] >= Left(correctWahana)->detail.bahanBangun[1] && bahanPengguna[2] >= Left(correctWahana)->detail.bahanBangun[2]){
                    addressStack VarUpgrade = AlokasiStack(2,Left(correctWahana)->detail.hargaBangun,Left(correctWahana)->detail.bahanBangun, 120, temp, Left(correctWahana)->detail.nama);
                    if (VarUpgrade!=NULL){
                        Push(S, VarUpgrade);
                        printf("Aksi Upgrade anda tercatat, Terima kasih!\n");
                    }else{
                        printf("Oops, Terjadi error pada sistem hubungi teknisi untuk memperbaiki\n");
                    }
                }else{
                    printf("Oops, uang atau bahan anda tidak mencukupi untuk melakukan aksi ini.\n");
                }
            }else if(input == 2){
                 if (uangPengguna >= Right(correctWahana)->detail.hargaBangun + totalUang && bahanPengguna[0] >= Right(correctWahana)->detail.bahanBangun[0] && bahanPengguna[1] >= Right(correctWahana)->detail.bahanBangun[1] && bahanPengguna[2] >= Right(correctWahana)->detail.bahanBangun[2]){
                    addressStack VarUpgrade = AlokasiStack(2,Right(correctWahana)->detail.hargaBangun,Right(correctWahana)->detail.bahanBangun, 120, temp, Right(correctWahana)->detail.nama);
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
    }else{
        printf("Oops, Anda tidak berada di sebelah wahana apa-apa.");
    }
}

POINT cekWahana(MATRIKS Map){
    boolean found = false;
    int i = 0;
    while (!found && i<30){
        if (isSebelah(Map.arrayWahana[i].lokasi,Player(Map))){
            found = true;
        }else{
            i++;
        }       
    }
    if (found){
        return Map.arrayWahana[i].lokasi;
    }else{
        return MakePOINT(-1,-1);
    } 
}

void UNDO(Stack *S){
    if (IsEmptyStack(*S)){
        printf("Stack sudah habis, tidak bisa undo\n");
    } else{
        addressStack P = (*S).TOP;
        Top(*S) = (*S).TOP->Next;
        DealokasiStack(P);
        printf("Yeay kamu berhasil undo!\n");
    }
}


void EXECUTE(Stack* SAwal, Stack* STarget, int* uangPengguna, JAM* jamPengguna, int bahanPengguna[], MATRIKS* Map, AddressTree* T){
    while (!IsEmptyStack(*SAwal)){
        addressStack P=NULL;
        P = (*SAwal).TOP;
        Push(STarget,P);
        (*SAwal).TOP = (*SAwal).TOP->Next;
    }
    while (!IsEmptyStack(*STarget))
    {
        Pop(STarget,uangPengguna,jamPengguna,bahanPengguna,Map,T);
    }
    printf("Berhasil menjalankan semua perintah!\n");
    printf("Masuk ke Main Phase . . .\n");
    
}

void MAIN(Stack* SAwal)
{
    while (!IsEmptyStack(*SAwal)){
        addressStack P = (*SAwal).TOP;
        (*SAwal).TOP = (*SAwal).TOP->Next;
        DealokasiStack(P);
    }
    printf("Semua perintah tidak dilakukan!\n");
    printf("Masuk ke Main Phase . . .\n");
}