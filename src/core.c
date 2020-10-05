#include "core.h"

int aire(Rect* r){
	return (r->c - r->a + 1)*(r->d - r->b + 1);
}

void printMap(int* grille, int w, int h){
	for(int y=0; y<h; y++){
		for(int x=0; x<w; x++){
			int value = get(grille, x, y, w);
			printf("\x1b[4%dm %d", value, value);
		}
		printf("\n");
	}
	printf("\x1b[0m");
}

int get(int* arr, int x, int y, int w){
	if(x<0 || y <0) return 0;
	return arr[x+y*w];
}

void set(int* arr, int x, int y, int w, int data){
	arr[x+y*w] = data;
}
