#include <stdio.h>
#include <math.h>

int main(){
	long int steps = 100;
	float T = 0.1;
	int L = 5;
	int S[L][L];	
	int PI[L], NI[L];
	for(int i = 1; i < L; i++){
		NI[i] = i + 1;
		PI[i] = i - 1;
	}
	NI[0] = 1;
	PI[0] = L-1;
	NI[L-1] = 0;
	float R;
	for(int i = 0; i < L; i++){//start config
		for(int j = 0; j < L; j++){
			R = (float)rand()/RAND_MAX;
			if(R > 0.5) S[i][j] = 1;
			else S[i][j] = -1;
			//printf("\t%d",S[i][j]);
		}
		//printf("\n");
	}
	int dE; 
	float omega;
	float B[5];
	for(int i = 0, d = -8; i < 5; i++, d += 4){
		B[i] = exp(-d/T);
		//printf("%d: %e\n",d,B[i]);
	}
	for(int i = 1; i <= steps; i++){//main loop
		for(int j = 0; j < L; j++){
			for(int k = 0; k < L; k++){
				if(S[j][k] == 1) S[j][k] = -1;
				else S[j][k] = 1;				
				dE = -2 * S[j][k] * ( S[NI[j]][k] + S[PI[j]][k] + S[j][NI[k]] + S[j][PI[k]] );
				//printf("dE%d:\t%d\n",i,dE);
				omega = exp(-dE/T);
				//printf("omega%d: %f\n",i,omega);
				R = (float)rand()/RAND_MAX;
				if(R > omega){//reversed accept condition
					if(S[j][k] == 1) S[j][k] = -1;
					else S[j][k] = 1;
				}
			}
		}
		//config analysis, data gathering
	}
	//calc average values
	return 0;
}
