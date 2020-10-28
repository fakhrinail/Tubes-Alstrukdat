#include <stdio.h>

void new_game();

void load_game();

void exit();

int main(){

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
    fgetc(stdin);


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
    scanf("%d", &pilihan);

    if (pilihan==1){
        new_game;
    }else if (pilihan==2){
        load_game;
    }else{
        exit;
    }

    return 0;
}