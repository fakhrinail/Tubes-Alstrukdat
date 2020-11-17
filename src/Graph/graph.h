#ifndef graph_H
#define graph_H

#include "../boolean.h"

typedef char contents;      //isi contents adalah alamat dari .txt file map
typedef NodeGraph* AddressGraph;

typedef struct {
    contents map[];
    AddressGraph Next[2];
} NodeGraph;

typedef struct{
    AddressGraph CURRENT;
} CurrentGraph;

#define Map(G) (G).map
#define Next0(G) (G).Next[0]
#define Next1(G) (G).Next[1]

#define Current(C) (C).CURRENT
#define CurrentMap(C) (C).CURRENT->map
#define CurrentNext0(C) (C).CURRENT->Next[0]
#define CurrentNext1(C) (C).CURRENT->Next[1]

void createEmptyCurrentGraph(CurrentGraph* CG);
/*
    I.S. CG sembarang
    F.S. CG bernilai NULL
*/

void createNodeGraph(NodeGraph* NG, contents alamat_map);
/*
    I.S. NG sembarang
    F.S. map dari NG berisi alamat_map dan Next dari NG sementara diinisialisasi NULL dan akan diisi di main program.
*/

#endif