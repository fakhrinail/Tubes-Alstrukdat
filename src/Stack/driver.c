#include "stacklist.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Stack S;
    CreateEmpty(&S);
    infotype cmd = 1;
    infotype uang = 1000;
    infotype jml[3] = {1,2,3};
    infotype waktu = 60;
    Push(&S,cmd,uang,&jml[3],waktu);
    printf("%d", S.TOP->jmlbahan[2]);
    return 0;
}