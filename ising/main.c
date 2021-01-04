#include <stdio.h>
#include <math.h>

int main(){
	long int steps = 100;
	float T = 0.1;
	int L = 5;
	int S[L][L];
	float s;
	int PI[L], NI[L];
	for(int i = 1; i < L; i++){
		NI[i] = i + 1;
		PI[i] = i - 1;
	}
	NI[0] = 1;
	PI[0] = L;
	NI[L-1] = 0;
	double k = 1.380649e-23;
	for(int i = 0; i < L; i++){//start config
		for(int j = 0; j < L; j++){
			s = (float)rand()/RAND_MAX;
			if(s > 0.5) S[i][j] = 1;
			else S[i][j] = -1;
			printf("\t%d",S[i][j]);
		}
		printf("\n");
	}
	float dE, omega;
	float R;
	for(int i = 1; i <= steps; i++){//main loop
		for(int j = 0; j < L; j++){
			for(int k = 0; k < L; k++){
				S[j][k] = -S[j][k];
				dE = -2 * S[j][k] * ( S[NI[j]][k] + S[PI[j]][k] + S[j][NI[k]] + S[j][PI[k]] );
				//printf("dE%d: %f\n",i,dE);
				omega = exp(-dE/(k*T));
				//printf("omega%d: %f\n",i,omega);
				R = (float)rand()\RAND_MAX;
				if(R > omega) S[j][k] = -S[j][k];//reversed accept condition
			}
		}
		//config analysis, data gathering
	}
	//calc average values
	return 0;
}
