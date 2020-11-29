#ifndef GRAPH_H
#define GRAPH_H

#include "../Matriks/matriks.c"
#include "../boolean.h"
#include "../ListLinier/listlinier.h"
#include <stdlib.h>

typedef int infograph;

typedef struct tElmtgraph *addressGraph;
typedef struct tElmtgraph {
	infograph info;
	List link;
	addressGraph next;
} ElmtGraph;

typedef struct {
	addressGraph First;
} Graph;


#define InfoGraph(P) (P)->info
#define NextGraph(P) (P)->next
#define Link(P) 	 (P)->link
#define FirstGraph(G) ((G).First)

void CreateEmptyGraph(Graph *G);

boolean IsGraphEmpty(Graph G);

addressGraph AlokasiGraph(infograph X);

void AddLink(Graph *G, infograph n, infograph p);

boolean Adjacent(Graph G, infograph n, infograph p);

addressGraph SearchGraph(Graph G, infograph X);

#endif