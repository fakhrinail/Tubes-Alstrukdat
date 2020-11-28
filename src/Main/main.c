#include <stdio.h>
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include "../Jam/jam.h"
#include "../Tree/tree.h"
#include "../ListArray/listarray.h"

WahanaTree W[3];        //List Wahana dari wahana.txt
AddressTree T[3];       //Pohon yang akan berisi List Wahana di atas
BahanBangunan material[3];
int uangPengguna;       //sebagai uang game
int listBahan[3];       //sebagai bahan bangunan yang dimiliki pengguna, 0 untuk kayu, 1 untuk batu, 2 untuk metal
JAM currentJam;         //sebagai jam di game

void new_game();

void load_game();

void exit();

int main(){

    /* Membuat Tree Wahana */
    
    DaftarWahana(W);
    DaftarTree(T,W);
    MakeTree(T[0],T[1],T[2]);

    /* Membuat List Bahan Bangunan */
    DaftarBahan(material);
    

    printf("\\=========================================================================/\n");
    printf("\\                                                                         /\n");
    printf("\\                                                                         /\n");
    printf("\\                  Selamat                                                /\n");
    printf("\\                          Datang                                         /\n");
    printf("\\                                  di                                     /\n");
    printf("\\                                     Willy Wangky's World                /\n");
    printf("\\                                                                         /\n");
    printf("\\                              KELOMPOK 10 K3                             /\n");
    printf("\\=========================================================================/\n");
    printf("\n");
    printf("\n");
    printf("Klik enter untuk melanjutkan.\n");
    STARTKATAi();


    printf("\\=========================================================================/\n");
    printf("\\                                                                         /\n");
    printf("\\                                NEW GAME(1)                              /\n");
    printf("\\                                                                         /\n");
    printf("\\                                LOAD GAME(2)                             /\n");
    printf("\\                                                                         /\n");
    printf("\\                                  EXIT(3)                                /\n");
    printf("\\                                                                         /\n");
    printf("\\=========================================================================/\n");
    printf("\n");
    printf("Masukkan pilihan anda. (1/2/3)\n");

    int pilihan;
    ADVKATAi();
    pilihan = StrToInt(CKataI);

    if (pilihan==1){
        new_game;
    }else if (pilihan==2){
        load_game;
    }else{
        exit;
    }

    return 0;
}