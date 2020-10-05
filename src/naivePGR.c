#include "naivePGR.h"

int plusGrandRect(int* grille, int w, int h){
	Rect* r = malloc(sizeof(Rect)); r->a = 0; r->b = 0; r->c = 0; r->d = 0;
	int aireR = aire(r);

	for(int y=0; y<h; y++){
		for(int x=0; x<w; x++){

			for(int y2=y; y2<h; y2++){
				for(int x2=x; x2<w; x2++){
					Rect testRect = {x, y, x2, y2};
					int aireT = aire(&testRect);

					if(rectEstVide(&testRect, grille, w) && aireT > aireR ){
						aireR = aireT;
						*r = testRect;
					}
				}
			}
		}
	}

	return aireR;
}

int rectEstVide(Rect* r, int* grille, int w){
	for(int x=r->a; x < r->c +1; x++){
		for(int y=r->b; y < r->d +1; y++){
			if(get(grille, x, y, w) != VIDE) return 0;
		}
	}
	return 1;
}
