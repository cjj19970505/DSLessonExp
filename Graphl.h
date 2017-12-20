#ifndef GRAPHL_H
#define GRAPHL_H
#include "Graphm.h"

//只有当其为头节点时data才有作用 
struct GLLink
{
	char data;
	int vert;
	struct GLLink *next;
};
typedef struct GLLink GLLink;
struct Graphl
{
	GLLink **vertex;
	int vertCount;
};
typedef struct Graphl Graphl;
Graphl *GL_Create(int vertexCount);
int GL_SetEdge(Graphl *graph, int from, int to, int weight);
int GL_SetFromGM(Graphl *gl, Graphm *gm);
void GL_Print(Graphl *gl);
#endif
