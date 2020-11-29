#include <stdio.h>
#include "../MesinKarakter-Kata/mesinkar+katafile.h"
#include "../MesinKarakter-Kata/mesinkar+katainput.h"
#include "../Jam/jam.h"
#include "../Tree/tree.h"
#include "../ListArray/listarray.h"
#include "../Matriks/matriks.h"


MATRIKS MAP1, MAP2, MAP3, MAP4;
WahanaTree W[3];        //List Wahana dari wahana.txt
AddressTree T[3];       //Pohon yang akan berisi List Wahana di atas
BahanBangunan material[3];
int uangPengguna;       //sebagai uang game
int listBahan[3];       //sebagai bahan bangunan yang dimiliki pengguna, 0 untuk kayu, 1 untuk batu, 2 untuk metal
JAM currentJam;         //sebagai jam di game
char namaPengguna[20];

void new_game()
{
    /* Load Map dari file */
    MakeMAP(&MAP1,"../../map1.txt");
    MakeMAP(&MAP2,"../../map2.txt");
    MakeMAP(&MAP3,"../../map3.txt");
    MakeMAP(&MAP4,"../../map4.txt");

    /* Memasukkan nama pengguna */
    MakeString20Empty(namaPengguna);
    ADVKATAi(); // sebagai scanf
    CopyString(namaPengguna,CKataI);
    
    /* Inisiasi preparation phase */
    boolean preparation = true;
    while(!exit){ // selama tidak exit 
        printf("Preparation Phase");
        TulisMap(MAP1);
        printf("Legend : \n A = Antrian \n P = Player \n W = Wahana \n O = Office \n G = Gerbang");
        printf("Nama : %s\n", namaPengguna);
        printf("Uang : %d\n", uangPengguna);
        printf("Waktu : ");
        TulisJAM(currentJam);
        printf("Masukkan perintah: ");
        ADVKATAi();
    }
}

void load_game();

void exit(){
    printf("  ___  ___  ___   _   _  ___  _   _     \n");       
    printf(" / __|/ _ \\/ _ \\ | | | |/ _ \\| | | |         \n");  
    printf(" \\__ \\  __/  __/ | |_| | (_) | |_| |           \n");
    printf(" |___/\\___|\\___|  \\__, |\\___/ \\__,_|           \n");
    printf("                   __/ |                       \n");
    printf("                  |___/ _   _                _ \n");
    printf("                 | |   | | (_)              | |\n");
    printf("  _ __   _____  _| |_  | |_ _ _ __ ___   ___| |\n");
    printf(" | '_ \\ / _ \\ \\/ / __| | __| | '_ ` _ \\ / _ \\ |\n");
    printf(" | | | |  __/>  <| |_  | |_| | | | | | |  __/_|\n");
    printf(" |_| |_|\\___/_/\\_\\\\__|  \\__|_|_| |_| |_|\\___(_)\n");
}

int main(){

    /* Membuat Tree Wahana */
    
    DaftarWahana(W);
    DaftarTree(T,W);
    MakeTree(T[0],T[1],T[2]);

    /* Membuat List Bahan Bangunan */
    DaftarBahan(material);


    printf(" __      __.__.__  .__                                          __           \n");
    printf("/  \\    /  \\__|  | |  | ___.__. __  _  _______    ____    ____ |  | _____.__.\n");
    printf("\\   \\/\\/   /  |  | |  |<   |  | \\ \\/ \\/ /\\__  \\  /    \\  / ___\\|  |/ <   |  |\n");
    printf(" \\        /|  |  |_|  |_\\___  |  \\     /  / __ \\|   |  \\/ /_/  >    < \\___  |\n");
    printf("  \\__/\\  / |__|____/____/ ____|   \\/\\_/  (____  /___|  /\\___  /|__|_ \\/ ____|\n");
    printf("       \\/               \\/                    \\/     \\//_____/      \\/\\/     \n");
    printf("                                            .__       .___\n");
    printf("                        __  _  _____________|  |    __| _/\n");
    printf("                        \\ \\/ \\/ /  _ \\_  __ \\  |   / __ | \n");
    printf("                         \\     (  <_> )  | \\/  |__/ /_/ | \n");
    printf("                          \\/\\_/ \\____/|__|  |____/\\____ | \n");
    printf("                                                       \\/ \n");
    printf("\n");
    printf("\n");
    printf("Klik enter untuk melanjutkan.\n");
    STARTKATAi();


    printf(" __| |____________________________________________| |__\n");
    printf("(__   ____________________________________________   __)\n");
    printf("   | |                                            | |\n");
    printf("   | |               1. New Game                  | |\n");
    printf("   | |                                            | |\n");
    printf("   | |               2. Load game                 | |\n");
    printf("   | |                                            | |\n");
    printf("   | |               3. Exit                      | |\n");
    printf(" __| |____________________________________________| |__\n");
    printf("(__   ____________________________________________   __)\n");
    printf("   | |                                            | |\n");

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