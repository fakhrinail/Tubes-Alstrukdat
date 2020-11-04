#include <stdlib.h>
#include <stdio.h>
#include "ADT_list_berkait.h"


AddressList AlokasiNodeList(Eltype jenis_upgrade){
    AddressList AL = (AddressList) malloc(sizeof(NodeList));
    Upgrade(AL) = jenis_upgrade;
    Next(AL) = NULL;

    return AL;
}

void Dealokasi(AddressList* alamat)
/*
    Mengdealokasikan memori sebesar sebuah node
*/
{
    free(*alamat);
}
