#include "Graphm.h"
#include "stdlib.h"
#include "stdio.h"
#include "IntQueue.h"

Graphm *GM_Create(int maxVertCount)
{
	Graphm *graph = (Graphm*)malloc(sizeof(Graphm));
	graph->adjMatrix = (int**)calloc(maxVertCount, sizeof(int*));
	char *data = (char*)calloc(maxVertCount, sizeof(char));
	for(int i=0; i < maxVertCount; i++)
	{
		graph->adjMatrix[i] = (int*)calloc(maxVertCount, sizeof(int));
		for(int j=0; j < maxVertCount; j++)
		{
			if(i==j)
			{
				graph->adjMatrix[i][j] = 0;
			}
			else
			{
				graph->adjMatrix[i][j] = -1;
			}
			
		}
	}
	graph->data = data;
	graph->vertCount = maxVertCount;
	return graph;
}
void GM_SetData(Graphm *graph, int vert, char data)
{
	graph->data[vert] = data;
}
char GM_GetData(Graphm *graph, int vert)
{
	return graph->data[vert];
}
void GM_Print(Graphm *graph)
{
	for(int i=0;i<graph->vertCount;i++)
	{
		for(int j=0;j<graph->vertCount;j++)
		{
			int w = GM_GetWeight(graph, i, j);
			if(w<0)
			{
				printf("-1 ",graph->adjMatrix[i][j]);
			}
			else
			{
				printf("%d ",graph->adjMatrix[i][j]);
			}
			
		}
		printf("\n");
	}
}
//返回成功或失败 
int GM_SetEdge(Graphm *graph, int from, int to, int weight)
{
	if(from >= graph->vertCount || to >= graph->vertCount)
	{
		return 0;
	}
	if(from == to)
	{
		printf("ERROR::不要对同一个顶点设置边\n");
		return -1;
	}
	graph->adjMatrix[from][to] = weight;
}
int GM_SetDoubleEdge(Graphm *graph, int v1, int v2, int weight)
{
	int r1 = GM_SetEdge(graph, v1, v2, weight);
	if(!r1)
	{
		return 0;
	}
	GM_SetEdge(graph, v2, v1, weight);
	return 1;
}
int GM_DeleteEdge(Graphm *graph, int from, int to)
{
	if(from >= graph->vertCount || to >= graph->vertCount)
	{
		return 0;
	}
	graph->adjMatrix[from][to] = -1;
}
int GM_GetWeight(Graphm *graph, int from, int to)
{
	if(from >= graph->vertCount || to >= graph->vertCount)
	{
		return -1;
	}
	return graph->adjMatrix[from][to];
}
int GM_FirstAdj(Graphm *graph, int oneVertex)
{
	for(int i=0;i<graph->vertCount;i++)
	{
		if(graph->adjMatrix[oneVertex][i] > 0)
		{
			return i;
		}
	}
	return -1;
}
int GM_NextAdj(Graphm *graph, int oneVertex, int preVertex)
{
	if(GM_GetWeight(graph, oneVertex, preVertex) < 0)
	{
		printf("ERROR::PREVERTEX IS NOT VALID\n");
		return -1;
	}
	for(int i = preVertex + 1; i < graph->vertCount; i++)
	{
		if(graph->adjMatrix[oneVertex][i] > 0)
		{
			return i;
		}
	}
	return -1;
}
void GM_DFS(Graphm *graph, int* visited, int currVert, void *operation(Graphm *graph, int vert))
{
	int visitedArrayCreatedHere = 0;
	if(visited==NULL)
	{
		visited = (int*)calloc(graph->vertCount, sizeof(int));
		if(visited==NULL)
		{
			printf("ERROR:内存不足\n");
			return;
		}
		visitedArrayCreatedHere = 1;
		for(int i=0; i < graph->vertCount; i++)
		{
			visited[i] = 0;
		}
	}
	if(visited[currVert])
	{
		return;
	}
	operation(graph, currVert);
	visited[currVert] = 1;
	int i = GM_FirstAdj(graph, currVert);
	do
	{
		GM_DFS(graph, visited, i, operation);
		i = GM_NextAdj(graph, currVert, i);
	}
	while(i > 0);
	
	//如果visited数组在这层创建，清除它 
	if(visitedArrayCreatedHere)
	{
		free(visited);
	}
}
void GM_BFS(Graphm *graph, int currVert, void *operation(Graphm *graph, int vert))
{
	int visited[graph->vertCount];
	for(int i=0;i<graph->vertCount;i++)
	{
		visited[i] = 0;
	}
	IntQueue *queue = IQ_Create();
	IQ_InQueue(queue, currVert);
	visited[currVert] = 1;
	while(!IQ_IsEmpty(queue))
	{
		int v;
		IQ_OutQueue(queue, &v);
		operation(graph, v);
		int curr = GM_FirstAdj(graph, v);
		do
		{
			if(!(visited[curr]))
			{
				IQ_InQueue(queue, curr);
				visited[curr] = 1;
			}
			curr = GM_NextAdj(graph, v, curr);
		}
		while(curr >= 0);
	}
	IQ_Delete(queue);
	
}
void GM_Delete(Graphm *graph)
{
	//等会再写 
}

