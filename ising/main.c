#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
	long int steps = 230000;
	int skip = 30000;
	int inter = 100;
	float T = atof(argv[1]);
	int L = atoi(argv[2]);
	int S[L][L], PI[L], NI[L];
	for(int i = 1; i < L; i++){
		NI[i] = i + 1;
		PI[i] = i - 1;
	}
	NI[0] = 1;
	PI[0] = L-1;
	NI[L-1] = 0;
	float R;
	for(int i = 0; i < L; i++){//initial config
		for(int j = 0; j < L; j++){
			R = (float)rand()/RAND_MAX;
			if(R > 0.5) S[i][j] = 1;
			else S[i][j] = -1;
			//printf("\t%d",S[i][j]);
		}
		//printf("\n");
	}
	int dE; 
	float omega, B[5];
	for(int i = 0, d = -8; i < 5; i++, d += 4){
		B[i] = exp(-d/T);
		//printf("%d: %e\n",d,B[i]);
	}
	int sTrial;
	float m = 0, mTemp = 0;
	for(int i = 1; i <= steps; i++){//main loop
		for(int j = 0; j < L; j++){
			for(int k = 0; k < L; k++){

				if(S[j][k] == 1) sTrial = -1;
				else sTrial = 1;
				
				dE = -2 * sTrial * ( S[NI[j]][k] + S[PI[j]][k] + S[j][NI[k]] + S[j][PI[k]] );
				if(dE < 0){
					S[j][k] = sTrial;
				}
				else{
					omega = exp(-dE/T);
					//printf("omega%d:\t%.3f\n",i,omega);
					R = (float)rand()/RAND_MAX;
					if(R < omega){//reversed accept condition
						S[j][k] = sTrial;
					}
				}
			}
		}	
		if(i%inter == 0 && i > skip){//gathering data for average values
			for(int i = 0; i < L; i++){
				for(int j = 0; j < L; j++){
					mTemp += S[i][j];
				}
			}
			mTemp = mTemp / (L*L);
			m += abs(mTemp);
			mTemp=0;
			//m = m / ((steps-skip)/inter);
			//printf("%e\n",m);
		}
	}
	m = m / ((steps-skip)/inter);
	printf("<m> = %e\tT* = %.2f\tL = %d\n",m,T,L);

	return 0;
}
