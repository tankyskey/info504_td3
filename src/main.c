#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "naivePGR.h"
#include "pgr2.h"
#include "stack.h"
#include "algo.h"
#include <time.h>
#define H 10
#define W 10

int check(int grille[4][4]){
	int diaga = 1, diagb = 1;
	for(int y=0; y<4; y++){
		if(grille[y][0] && grille[y][1] && grille[y][2] && grille[y][3])
			return 1;
		if(!grille[y][y])
			diaga = 0;
	}
	if(diaga)
		return 1;

	for(int x=0; x<4; x++){
		if(grille[0][x] && grille[1][x] && grille[2][x] && grille[3][x])
			return 1;
		if(!grille[x][3-x])
			diagb = 0;
	}

	return diagb;
}

void testImg(){
	int test[H][W] = {
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0}
	};

	int* image = integralImage((int*)test, W, H);
	printMap((int*)test, W, H);

	int p = plusGrandRect((int*)test, W, H);
	printf("aire plusGrandRect: %d\n", p);
	printf("\n\nintegralImage at (5, 5): %d\n", get(image, 5, 5, W));
	printMap(image, W, H);
}

int main(){

	int test[H][W] = {
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0}
	};

	printMap((int*)test, W, H);
	clock_t t0 = clock(), t1;
	printf("pgr: %d\n", plusGrandRect((int*)test, W, H));
	t1 = clock();
	printf("dt=%f\n\n", (double)(t1-t0));

	t0 = clock();
	printf("pgr2: %d\n", plusGrandRect2((int*)test, W, H));
	t1 = clock();
	printf("dt=%f", (double)(t1-t0));
	return 0;
}
