#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void printToFile (int k, double var);
double varCalc (int x, int n, int k);
void drunkard (int n, int k);

int main(){
	int k = 5; //number of drunkards
	int n = 30000; //number of steps
	drunkard(n, k);
	return 0;
}

void drunkard (int n, int k){
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
		printf("k:%d \t Xn:%d \n",i,x);
		double var = varCalc(x, n);
		printf("var:%f \n\n",var);
	}
}

double varCalc (int xn, int n, int k){
	double var;
	double sig;
	var = xn*xn;
	sig = sqrt(var);
	return var;
}

void printToFile (int k, double var){

}
