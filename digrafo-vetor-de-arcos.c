/*
	Vetor de arcos
*/

#include <stdio.h>
#include <stdlib.h>

/* Vértices de digrafos são representados por objetos do tipo Vertex. */
#define Vertex int

/* REPRESENTAÇÃO POR VETOR DE ARCOS: 
	Um objeto do tipo Arc representa um arco com ponta inicial
 	V e ponta final w. */

 typedef struct {
 	Vertex v, w;
 }Arc;

 /* A funçao ARC devolve um arco com ponta inicial v e ponta final w. */

 Arc ARC(Vertex v, Vertex w) {
 	Arc a;
 	a.v = v, a.w= w;
 	return a;
 }

/* REPRENSETAÇÃO POR VETOR DE ARCOS: A estrutura diagraph representa um digrafo. 
	O campo V contém o número de vértices e o campo A contém o número de arcos do digrafo.
	O campor arcs é um ponteiro para o vetor de arcos do digraco.
	O campo maxA contém o número máximo de arcos que o vetor arcs comporta. */

struct digraph {
	int V;
	int A;
	Arc *arcs;
	int maxA;
};

/* Um objeto do tipo Digraph contém o endereço de um digraph. */

typedef struct digraph *Digraph;

Digraph DIGRAPHinit( int V){
	Digraph G = malloc( sizeof (struct digraph));
	G->V = V;
	G->A = 0;
	G->maxA = V;
	G->arcs = malloc( V * sizeof (Arc));
	return G;
}

void DIGRAPHinsertA( Digraph G, Vertex v, Vertex w){
	int i;
	for(i = 0; i < G->A; ++i){
		Arc a = G->arcs[i];
		if(a.v == v && a.w == w) return;
	}

	if(G->A == G->maxA){
		G->maxA *= 2;
		G->arcs = realloc( G->arcs, G->maxA * sizeof(Arc));
	}
	G->arcs[G->A] = ARC( v, w);
	G->A++;
}

void DIGRAPHshow( Digraph G){
	int i;
	for(i = 0; i < G->A; i++){
		Arc a = G->arcs[i];
		printf("%d-%d ", a.v, a.w);
	}
	printf("\n");
}

int main(){
	//Cria um digrafo com 3 vértices
	Digraph g = DIGRAPHinit(3);
	//Insere um arco 1-0
	DIGRAPHinsertA(g, 1, 0);
	//Insere um arco 2-0
	DIGRAPHinsertA(g, 2, 0);
	//Insere um 3-0
	DIGRAPHinsertA(g, 3, 0);
	//Impreme em uma linha todos os arcos do digrafo
	DIGRAPHshow(g);
	return 0;
}

