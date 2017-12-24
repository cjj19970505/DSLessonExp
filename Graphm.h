#ifndef GRAPHM_H
#define GRAPHM_H
#include "GData.h"
struct Graphm
{
	int **adjMatrix;
	int vertCount;
	char *data;
};
typedef struct Graphm Graphm;
Graphm *GM_Create(int maxVertCount);
void GM_Print(Graphm *graph);
void GM_Delete(Graphm *graph);
int GM_SetEdge(Graphm *graph, int from, int to, int weight);
int GM_DeleteEdge(Graphm *graph, int from, int to);
int GM_FirstAdj(Graphm *graph, int oneVertex);
int GM_NextAdj(Graphm *graph, int oneVertex, int preVertex);
int GM_GetWeight(Graphm *graph, int from, int to);
int GM_SetDoubleEdge(Graphm *graph, int v1, int v2, int weight);
void GM_DFS(Graphm *graph, int* visited, int currVert, void (*operation)(Graphm *graph, int vert));
void GM_BFS(Graphm *graph, int currVert, void (*operation)(Graphm *graph, int vert));
void GM_SetData(Graphm *graph, int vert, char data);
char GM_GetData(Graphm *graph, int vert);
#endif
