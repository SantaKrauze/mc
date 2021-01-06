#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
	long int steps = 230000;
	int skip = 30000;
	int interval = 100;

	float T = atof(argv[1]);
	int L = atoi(argv[2]);
	int S[L][L], P[L], N[L];
	for(int i = 0; i < L; i++){//nearest neighbor
		N[i] = i + 1;//next
		P[i] = i - 1;//previous
	}
	P[0] = L-1;
	N[L-1] = 0;
	float R;
	for(int i = 0; i < L; i++){//initial config
		for(int j = 0; j < L; j++){
			//R = (float)rand()/RAND_MAX;
			//if(R > 0.5) S[i][j] = 1;
			//else S[i][j] = -1;
			S[i][j] = 1;
		}
	}
	int dE; 
	float omega;
	
	int sTrial;
	float m = 0, mTemp, usedConfigs = (steps-skip)/interval;
	for(int i = 1; i <= steps; i++){//main loop
		for(int j = 0; j < L; j++){
			for(int k = 0; k < L; k++){
				sTrial = -S[j][k];
				dE = 2*S[j][k] * ( S[N[j]][k] + S[P[j]][k] + S[j][N[k]] + S[j][P[k]] );
				if(dE < 0){
					S[j][k] = sTrial;
				}
				else{
					omega = exp(-dE/T);
					R = (float)rand()/RAND_MAX;
					if(R < omega){
						S[j][k] = sTrial;
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
				//mTemp /+ (L*L);
				//m += abs(mTemp);
			}
			mTemp = abs(mTemp) / (L*L);
			m += mTemp;
			//printf("%e\n",m);
		}
	}
	m /= usedConfigs;
	printf("<m> = %.2e\tT* = %.2f\tL = %d\n",m,T,L);

	return 0;
}
