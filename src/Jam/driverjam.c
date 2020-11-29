#include "jam.h"
#include <stdio.h>
#include "boolean.h"

int main(){
    JAM asu = MakeJAM(22,00);
    TulisJAM(asu);
    boolean cond;
    cond = IsJAMValid(asu.HH,asu.MM,00);
    printf("IS JAM VALID : %d\n",cond);
    int menitnya;
    menitnya = JAMToMenit(asu);
    printf("JAM TERSEBUT APABILA DALAM MENIT : %d menit\n",menitnya);
    JAM new = MenitToJAM(1310);
    TulisJAM(new);
    int menitnya2;
    menitnya2 = JAMToMenit(new);
    printf("JAM TERSEBUT APABILA DALAM MENIT : %d menit\n",menitnya2);
    printf("JEQ : %d\n",JEQ(asu,new));
    printf("JNEQ : %d\n",JNEQ(asu,new));
    printf("JLT : %d\n",JLT(asu,new));
    printf("JGT : %d\n",JGT(asu,new));
    return 0;
}   