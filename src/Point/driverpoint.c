#include <stdio.h>
#include "point.h"

int main() {
    POINT P1;
    POINT P2;
    int X1,Y1,X2,Y2;
    printf("Masukkan nilai dari x dan y point pertama\n");
    scanf("%d %d", &X1, &Y1);
    printf("Masukkan nilai dari x dan y point kedua\n");
    scanf("%d %d", &X2, &Y2);
    P1 = MakePOINT(X1,Y1);
    P2 = MakePOINT(X2,Y2);

    if (isNil(P1))
    {
        printf("Point pertama kosong\n");
    }
    else
    {
        printf("Point pertama ada isinya\n");
    }

    if (EQPoint(P1,P2))
    {
        printf("Point pertama dan kedua sama\n");
    }
    else if (NEQPoint(P1,P2))
    {
        printf("Point pertama dan kedua sama\n");
    }
    
    if (isBersebelahan(P1,P2))
    {
        printf("Point pertama dan kedua bersebelahan\n");
    }
    else
    {
        printf("Point pertama dan kedua tidak bersebelahan\n");
    }
    
    return 0;
}