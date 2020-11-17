#ifndef list_berkait_H
#define list_berkait_H

#include "../boolean.h"

typedef char Eltype;   
typedef NodeList* AddressList;
typedef struct {
    Eltype upgrade;            //Di sini gue kepikiran untuk aksinya dikasih satu char aja, misal 'a' upgrade pertama, 'b' upgrade kedua. Tapi pada akhirnya ini bakal nyesuain dengan daftar upgrade di ADT Tree
    AddressList Next;           
} NodeList;

typedef struct{
    AddressList FIRST;
    AddressList LAST;
} Wahana;


#define First(W) (W).FIRST
#define Last(W) (W).LAST
#define Next(NL) (NL)->Next
#define Upgrade(NL) (NL)->upgrade


AddressList AlokasiNodeList(Eltype jenis_upgrade);
/*
    Mengalokasikan sebuah node ke memori
*/

void Dealokasi();
/*
    Mengdealokasikan memori sebesar sebuah node
*/


#endif