#include "graph.c"
#include "stdio.h"
#include "stdlib.h"

int main(){
    int n;
    scanf(n);
    Graph G;
    addressGraph P;
    P = FirstGraph(G);
    while(InfoGraph(P))
    for (int i=0;i<n;i++){
        NextGraph(P)=AlokasiGraph(i);
        P=NextGraph(P);
    }
    PrintGraph(G);
}