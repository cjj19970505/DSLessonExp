#include <stdio.h>
#include <stdlib.h>
#include "Graphm.h"
#include "IntQueue.h"
#include "Graphl.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printVertex(Graphm *graph, int vert);
int main(int argc, char *argv[]) {
	Graphm *g = GM_Create(9);
	/*
	GM_SetDoubleEdge(g,0,1,2);
	GM_SetDoubleEdge(g,0,2,2);
	GM_SetDoubleEdge(g,0,3,2);
	GM_SetDoubleEdge(g,1,2,2);
	GM_SetDoubleEdge(g,1,4,2);
	GM_SetDoubleEdge(g,2,5,2);
	GM_SetDoubleEdge(g,3,5,2);
	GM_SetDoubleEdge(g,4,6,2);
	GM_SetDoubleEdge(g,5,7,2);
	GM_SetDoubleEdge(g,6,8,2);
	GM_SetDoubleEdge(g,7,8,2);
	GM_SetDoubleEdge(g,0,1,2);*/
	
	
	GM_SetDoubleEdge(g,0,1,2);
	GM_SetDoubleEdge(g,0,2,2);
	GM_SetDoubleEdge(g,0,3,2);
	GM_SetDoubleEdge(g,1,2,2);
	GM_SetDoubleEdge(g,1,4,2);
	GM_SetDoubleEdge(g,2,5,2);
	GM_SetDoubleEdge(g,2,8,2);
	GM_SetDoubleEdge(g,3,5,2);
	GM_SetDoubleEdge(g,4,6,2);
	GM_SetDoubleEdge(g,5,7,2);
	GM_SetDoubleEdge(g,7,8,2);
	
	
	GM_SetData(g,0,'A');
	GM_SetData(g,1,'B');
	GM_SetData(g,2,'C');
	GM_SetData(g,3,'D');
	GM_SetData(g,4,'E');
	GM_SetData(g,5,'F');
	GM_SetData(g,6,'G');
	GM_SetData(g,7,'H');
	GM_SetData(g,8,'I');
	GM_Print(g);
	GM_DFS(g,NULL,0,printVertex);
	printf("\n==============\n");
	GM_BFS(g, 0, printVertex);
	Graphl *gl = GL_Create(9);
	GL_SetFromGM(gl, g);
	printf("\n======================================\n");
	GL_Print(gl);
	return 0;
}

void printVertex(Graphm *graph, int vert)
{
	printf("%c ",GM_GetData(graph,vert));
}
