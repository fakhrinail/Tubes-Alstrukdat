#include "graph.h"
#include <stdio.h>


void CreateEmptyGraph(Graph *G){
    First(*G)=Nil;
}

boolean IsGraphEmpty(Graph G){
    return (First(G)==Nil);
}

void AddLink(Graph *G, infograph n, infograph p)
{
    addressGraph tempn, tempp;

    tempn = FirstGraph(*G);
    while(InfoGraph(tempn)!=n){
        tempn = NextGraph(tempn);
    }
    if (Search(Link(tempn),p)==Nil){ 
        InsVLast(&Link(tempn),p);
    }

    tempp = FirstGraph(*G);
    while (InfoGraph(tempp)!=p){
        tempp=NextGraph(tempp);
    }
    if (Search(Link(tempp),n)==Nil){
        InsVLast(&Link(tempp),n);
    }
}
void PrintGraph(Graph G)
{
    printf("[");
    if(!IsGraphEmpty(G)){
        addressGraph P=FirstGraph(G);
        printf("%d",InfoGraph(P));
        P=NextGraph(P);
        while(P!=Nil){
            printf(",%d",InfoGraph(P));
            P=NextGraph(P);
        }
    }
    printf("]\n");
}


boolean Adjacent(Graph G, infograph n, infograph p)
{
    addressGraph tempn;
    boolean cek=false;
    tempn = FirstGraph(G);
    while (InfoGraph(tempn) != n){
        tempn = NextGraph(tempn);
    }
    if (Search(Link(tempn),p)!=Nil){
        cek=true;
    }
    return cek;
}

addressGraph SearchGraph(Graph G, infograph X)
{
    addressGraph P;
    while (InfoGraph(P)!=X && NextGraph(P)!=Nil){
        P=NextGraph(P);
    }
    if(InfoGraph(P)!=X){
        P=Nil;
    }
    return P;
}