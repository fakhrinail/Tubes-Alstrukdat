#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void createEmptyCurrentGraph(CurrentGraph* CG){
    Current(*CG) = NULL;
}

void createNodeGraph(NodeGraph* NG, contents alamat_map){
    Map(*NG) = alamat_map;
    Next0(*NG) = NULL;
    Next1(*NG) = NULL;
}