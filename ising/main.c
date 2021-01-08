#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]){
	long int steps = 230000;
	int skip = 30000;
	int interval = 100;

	float T = atof(argv[1])/10;
	float R;
	int L = atoi(argv[2]);
	int S[L][L], P[L], N[L];

	for(int i = 0; i < L; i++){//nearest neighbor
		N[i] = i + 1;//next
		P[i] = i - 1;//previous
	}
	P[0] = L-1;
	N[L-1] = 0;

	for(int i = 0; i < L; i++){//initial config
		for(int j = 0; j < L; j++){
			S[i][j] = 1;
		}
	}

	int dE; 
	float omega, m = 0, mTemp, usedConfigs = (steps-skip)/interval;
	for(int i = 1; i <= steps; i++){//main loop
		for(int j = 0; j < L; j++){
			for(int k = 0; k < L; k++){
				dE = 2*S[j][k] * ( S[N[j]][k] + S[P[j]][k] + S[j][N[k]] + S[j][P[k]] );
				if(dE < 0){
					S[j][k] = -S[j][k];
				}
				else{
					omega = exp(-dE/T);
					R = (float)rand()/RAND_MAX;
					if(R < omega){
						S[j][k] = -S[j][k];
					}
				}
			}
		}	
		if(i%interval == 0 && i >= skip){//gathering data for average values
			mTemp = 0;
			for(int i = 0; i < L; i++){
				for(int j = 0; j < L; j++){
					mTemp += S[i][j];
				}
			}
			if(atoi(argv[3]) == 2){
				mTemp /= (L*L);
				//m += mTemp;
				if(i%2000 == 0){
					printf("%.3e\t%d\n",mTemp,i);
				}
			}
			else{
				mTemp = abs(mTemp) / (L*L);
				m += mTemp;
			}	
		}
	}
	if(atoi(argv[3]) != 2) {
		m /= usedConfigs;
		printf("%.3e\t%.3f\t%d\n", m, T, L);
	}
	if(atoi(argv[3]) == 1){
		FILE *fptr;
		char size[3];
		snprintf(size, sizeof(size), "%d", L);
		fptr = fopen(size,"w");
		for(int i = 0; i < L; i++){
			for(int j = 0; j < L; j++){
				fprintf(fptr,"%d\t",S[i][j]);
			}
			fprintf(fptr,"\n");
		}
		fclose(fptr);
	}	

	return 0;
}
