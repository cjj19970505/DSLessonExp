#include "Graphl.h"
#include <stdlib.h>
#include <stdio.h>
GLLink *GL_NewGLLink(int vert, char data);
Graphl *GL_Create(int vertexCount)
{
	Graphl *gl = (Graphl*)malloc(sizeof(Graphl));
	gl->vertex = (GLLink**)calloc(vertexCount,sizeof(GLLink*));
	gl->vertCount = vertexCount;
	for(int i=0;i<vertexCount; i++)
	{
		gl->vertex[i] = GL_NewGLLink(i,'A');
	}
	return gl;
}
GLLink *GL_NewGLLink(int vert, char data)
{
	GLLink *glink = malloc(sizeof(GLLink));
	glink->vert = vert;
	glink->data = data;
	glink->next = NULL;
	return glink;
}
int GL_SetFromGM(Graphl *gl, Graphm *gm)
{
	if(gm->vertCount != gl->vertCount)
	{
		printf("ERROR::gl图和gm图的顶点个数不同");
		return 0;
	}
	for(int i = 0; i < gm->vertCount; i++)
	{
		gl->vertex[i]->data = gm->data[i];
	}
	for(int i = 0; i < gm->vertCount; i++)
	{
		for(int j = 0; j < gm->vertCount; j++)
		{
			if((gm->adjMatrix)[i][j] > 0)
			{
				GL_SetEdge(gl, i, j, 2);
			}
		}
	}
	return 1;
}
int GL_SetEdge(Graphl *graph, int from, int to, int weight)
{
	GLLink *vert = graph->vertex[from];
	GLLink *curr = vert->next;
	GLLink *tail = vert;
	int alreadyHave = 0;
	while(curr != NULL)
	{
		if(curr->vert == to)
		{
			alreadyHave = 1;
			break;
		}
		if(curr->next == NULL)
		{
			tail = curr;
		}
		curr = curr->next;
	}
	if(alreadyHave)
	{
		return 0;
	}
	//printf("\njjj");
	GLLink *newLink = GL_NewGLLink(to, graph->vertex[to]->data);
	tail->next = newLink;
	//printf("\njjj");
	return 1;
	
}
void GL_Print(Graphl *gl)
{
	for(int i = 0; i < gl->vertCount; i++)
	{
		printf("[%d:%c] --  ",i,gl->vertex[i]->data);
		GLLink *adj = gl->vertex[i]->next;
		while(adj != NULL)
		{
			printf("(%d:%c)",adj->vert,gl->vertex[adj->vert]->data);
			if(adj->next != NULL)
			{
				printf("-->");
			}
			adj = adj->next;
		}
		printf("\n");
	}
}
