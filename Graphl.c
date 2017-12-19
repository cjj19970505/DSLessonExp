#include "Graphl.h"
#include <stdlib.h>
#include "Graphm.h"
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
	
}
GLLink *GL_CreateLink(char data)
{
	GLLink *out = (GLLink*
}
