#ifndef GRAPHL_H
#define GRAPHL_H
struct GLLink
{
	char data;
	struct GLLink *next;
};
typedef struct GLLink GLLink;
struct Graphl
{
	GLLink **vertex;
};
typedef struct Graphl Graphl;
#endif
