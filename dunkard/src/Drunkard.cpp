#include "Drunkard.hpp"

Drunkard::Drunkard(){
	int x = 0;
	float r;
	for (int i = 1; i <= k; i++){
		for (int j = 0; j < n; j++){
			r = (float)rand()/RAND_MAX;
			if (r > 0.5){
				x = x + 1;
				//printf("k:%d val:%f x:%d\n",i,r,x);
			}
			else{
				x = x - 1;
				//printf("k:%d val:%f x:%d\n",i,r,x);
			}
		}
		double var = varCalc(x, n);
	}
}

void Drunkard::printToFile(){
}

double Drunkard::varCalc(){
	
}


