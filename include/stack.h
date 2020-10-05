#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int *bp, *sp, peak;
	int size;
} Stack;

void mkStack(Stack* s, int size);
void pushStack(int data, Stack* s);
int popStack(Stack* s);
int getStack(Stack* s);
void freeStack(Stack* s);
void cpyInTab(Stack* s, int* tab);
int stackPeak(Stack* s);
int stackIsEmpty(Stack* s);

#endif 
