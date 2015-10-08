/*
	Matriz de adjacência
*/

#include <stdlib.h>

int **MATRIXint(int, int, int);

struct digraph{
	int V;
	int A;
	int **adj;
};

typedef struct digraph *Digraph;

Digraph DIGRAPHinit( int V ){
	Digraph G = malloc ( sizeof *G);
	G->V = V;
	G->A = 0;
	G->adj = MATRIXint(V, V, 0);
	return G;
}

int **MATRIXint(int r, int c, int val){
	//TODO continuar implementação...
	return 0;
}