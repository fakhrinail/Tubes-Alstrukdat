#include "listarray.h"
#include <stdio.h>

void DaftarBahan(BahanBangunan listbahan[])
{
    int i = 0;
    STARTKATAf("../../doc/material.txt");
    while (!EndFile)
    {
        while (!EndLine)
        {
            MakeString20Empty(listbahan[i].namabahan);
            printf("%s\n",CKataF);
            CopyString(listbahan[i].namabahan,CKataF);
            ADVKATAf();
            listbahan[i].hargabahan = StrToInt(CKataF);
        }
        ADVf();     //maju ke line di bawahnya
        i++;
    }
}