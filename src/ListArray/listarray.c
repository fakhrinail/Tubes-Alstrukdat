#include "listarray.h"

void DaftarBahan(BahanBangunan listbahan[])
{
    int i = 0;
    STARTKATAf("../../doc/material.txt");
    while (!EndFile)
    {
        while (!EndLine)
        {
            CopyString(listbahan[i].namabahan,CKataF);
            ADVKATAf();
            listbahan[i].hargabahan = StrToInt(CKataF);
        }
        ADVKATAf();     //maju ke line di bawahnya
        i++;
    }
}