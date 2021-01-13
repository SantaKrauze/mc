#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]){
	long int steps = 230000;
	//long int steps = 2300000;
	int skip = 30000;
	//int interval = 100;
	int interval=1000;

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
		if(atoi(argv[3]) == 2){//getting flips
				mTemp = 0;
				for(int i = 0; i < L; i++){
					for(int j = 0; j < L; j++){
						mTemp += S[i][j];
					}
				}
				mTemp /= (L*L);
				//m += mTemp;
				if(i%(steps/1000) == 0){
					printf("%.3e\t%d\n",mTemp,i);
				}
			}
		if(i%interval == 0 && i >= skip){//gathering data for average m
			mTemp = 0;
			for(int i = 0; i < L; i++){
				for(int j = 0; j < L; j++){
					mTemp += S[i][j];
				}
			}	
			mTemp = abs(mTemp) / (L*L);
			m += mTemp;
				
		}
	}
	if(atoi(argv[3]) == 0) {
		m /= usedConfigs;
		printf("%.3e\t%.3f\t%d\n", m, T, L);
	}
	if(atoi(argv[3]) == 1){//getting config
		FILE *fptr;
		//char name[10];
		//snprintf(name, sizeof(name), "%f", L);
		fptr = fopen(argv[4],"w");
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
