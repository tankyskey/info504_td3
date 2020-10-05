#include "pgr2.h"
#include "tree.h"

int plusGrandRectHisto(int* histogramme, int w){
	int maxArea = 0;
	int ccArea = 0;
	int i=0;
	int tp;
	Stack s;
	mkStack(&s, w);

	while( i<w ){
		if(stackIsEmpty(&s) || histogramme[i] >= histogramme[getStack(&s)])
			pushStack(i++, &s);
		else{
			tp = popStack(&s);
			ccArea = histogramme[tp] * (stackIsEmpty(&s) ? i : i - getStack(&s) -1);
			if(maxArea < ccArea)
				maxArea = ccArea;
		}
	}

	while( !stackIsEmpty(&s) ){
		tp = popStack(&s);
		ccArea = histogramme[tp] * (stackIsEmpty(&s) ? i : i - getStack(&s) -1);
		if(maxArea < ccArea)
			maxArea = ccArea;
	}

	return maxArea;
}

int plusGrandRect2(int* grille, int w, int h){
	int histogramme[w];
	for(int i=0; i<w; i++)
		histogramme[i] = 0;
	int maxArea = 0;
	int ccArea = 0;

	for(int i=0; i<h*w; i++){
		if(!grille[i])
			histogramme[i%w]++;
		else
			histogramme[i%w] = 0;

		if( !(i%w) ) {
			ccArea = plusGrandRectHisto(histogramme, w);
			if(maxArea < ccArea)
				maxArea = ccArea;
		}
	}

	return maxArea;
}
