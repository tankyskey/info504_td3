#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef struct Tree{
	int data;
	struct Tree *fg;
	struct Tree *fd;
}Tree;

void printTree(Tree* tree);

#endif 
