#include "2eggs.h"

int height_threshold(int N, int Q) {
	int p = 1;
	for(int i=Q; i<N and Q > 1; p=i+1, Q--, i+=Q) {
		if(drop_egg(1, i)) {  
			for(int j=p; j<i; ++j) 
				if(drop_egg(2, j)) return j;
			return i;
		}
	}
	for(int j=p; j<N; ++j) {
		if(drop_egg(2, j)) {
			return j;
		}
	}
	return N;
}