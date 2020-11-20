#include "stackt.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

void PrintStack(Stack S){
    while(!IsEmpty(S)) {
        int data;
        Pop(&S,&data);
        printf("%d\n",data);
    }
}

void UNDO(Stack *S, infotype *res){
    Pop(S,res);
}

void EXECUTE(Stack S){
    Stack new;
    CreateEmpty(&new);
    infotype temp;
    while (!IsEmpty(S)){
        Pop(&S,&temp);
        Push(&new,temp);
    }
    PrintStack(new);
}
void MAIN(Stack S){
    infotype anjg;
    while (!IsEmpty(S)){
        Pop(&S,&anjg);
        printf("Run(anjg)\n");
    }   
}
int main(){
    Stack temp;
    CreateEmpty(&temp);
    Push(&temp,1);
    Push(&temp,2);
    Push(&temp,3);
    Push(&temp,4);
    printf("Ini stack mula2  \n");
    PrintStack(temp);
    printf("\n");
    infotype tempik;
    UNDO(&temp,&tempik);
    printf("Ini stack setelah di Undo\n");
    PrintStack(temp);
    printf("\n");
    printf("Ini perintah yang di Undo\n");
    printf("%d\n",tempik);
    printf("\n");
    printf("Ini sudah siap dilaksanakan\n");
    EXECUTE(temp);
    printf("\nIni Proses Run nya\n");
    MAIN(temp);

    return 0;
}