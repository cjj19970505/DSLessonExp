#include "Graphl.h"
#include <stdlib.h>

void GL_Create(int vertexCount)
{
	Graphl *gl = (Graphl*)malloc(sizeof(Graphl));
	gl->vertex = (GLLink**)calloc(vertexCount,sizeof(GLLink*));
	for(int i=0;i<vertexCount; i++)
	{
		gl->vertex[i] = NULL;
	}
}
void GL_SetFromGM(Graphm *gm)
{
	for(int i = 0; i < gm->vertexCount; i++)
	{
		
	}
}
GLLink *GL_CreateLink(char data)
{
	
}
void GL_SetEdge()
{
	
}
