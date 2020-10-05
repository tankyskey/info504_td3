#include "stack.h"

void mkStack(Stack* s, int size){
	if(s == NULL)
		s = malloc(sizeof(Stack));
	s->bp = malloc(sizeof(int)*size);
	s->size = size;
	s->sp = s->bp;
}

void pushStack(int data, Stack* s){
	if(s->size <= s->sp - s->bp){
		s->size *= 2;
		s->bp = realloc(s->bp, s->size);
	}
	*(s->sp++) = data;
}

int popStack(Stack* s){
	return *(--s->sp);
}

int getStack(Stack* s){
	return s->sp[-1];
}

void freeStack(Stack* s){
	free(s->bp);
}

void cpyInTab(Stack* s, int* tab){
	for(int i=0; s->bp+i != s->sp; i++)
		tab[i] = s->bp[0];
}

int stackPeak(Stack* s){
	return (s->sp) - (s->bp);
}

int stackIsEmpty(Stack* s){
	return s->sp == s->bp;
}
