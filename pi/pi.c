#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	float x,y,pi;
	int n = 100000000;
	int no = 0;
	for (int i = 0; i < n; i++){
		x = (float)rand()/RAND_MAX;
		y = (float)rand()/RAND_MAX;
		//printf("%f %f \n",x,y);
		if (x*x+y*y < 1){
			no = no + 1;
		}
	}
	pi = (float)4*no/n;
	printf("\n%f \n",pi);
	return 0;
}
