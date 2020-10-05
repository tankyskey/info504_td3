#include "tree.h"


void printTreeRec(Tree* tree, int tab){
	if(tree != NULL){
		printTreeRec(tree->fd, tab+1);

		for(int i=0; i!=tab;i++) printf("    ");
		printf("%d\n", tree->data);

		printTreeRec(tree->fg, tab+1);
	}
}

void printTree(Tree* tree){
	printTreeRec(tree, 0);
}
