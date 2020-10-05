#include "algo.h"

void castTreeInStack(Tree* tree, Stack* s){
	if(tree != NULL){
		castTreeInStack(tree->fg, s);
		pushStack(tree->data, s);
		castTreeInStack(tree->fd, s);
	}
}

void treeSortRec(int data, Tree** tree){
	if(*tree == NULL){
		*tree = malloc(sizeof(tree));
		(*tree)->data = data; (*tree)->fd = NULL; (*tree)->fg = NULL;
	} 
	else if(data < (*tree)->data) treeSortRec(data, &(*tree)->fg);
	else treeSortRec(data, &(*tree)->fd);
}

void treeSort(int* tab, int w){
	Tree* tree = NULL;
	Stack s;

	for(int i=0; i<w; i++)
		treeSortRec(tab[i], &tree);
	castTreeInStack(tree, &s);
	cpyInTab(&s, tab);
}



int* integralImage(int* grille, int w, int h){
	int* image = malloc(sizeof(int)*w*h);

	for(int y=0; y<h; y++)
		for(int x=0; x<w; x++)
			set(image, x, y, w, get(image, x, y-1, w) + get(image, x-1, y, w) - get(image, x-1, y-1, w) + get(grille, x, y, w));
		
	return image;
}
