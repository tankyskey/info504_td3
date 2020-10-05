#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VIDE 0

typedef struct{
	int a, b, c, d;
}Rect;

int aire(Rect* r);
void printMap(int* grille, int w, int h);
int get(int* arr, int x, int y, int w);
void set(int* arr, int x, int y, int w, int data);

#endif 
