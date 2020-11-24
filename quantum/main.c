#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define TSIZE 800
#define UNIT 0.01

float indexToX(int index);
//float randomPhi(int index);

int main(){
	int steps = 1000000, index;
	float phiStart = 0.01, dPhi = 0.1;
	float phiTrial, r, denominator = 0 , phi[TSIZE], U = 0, T = 0, numerator, E0;
	for (int i = 0; i < TSIZE; i++) {
		phi[i] = phiStart;
		float x = indexToX(i);
		U = U + (phi[i] * phi[i] * x * x * 0.5);//potential energy
		denominator = denominator + phi[i] * phi[i];
	}
	for (int i = 1; i < TSIZE-1; i++) T = T + phi[i] * (2 * phi[i] - phi[i-1] - phi[i+1]);
	T = T + (phi[0] * (2 * phi[0] - phi[1]) + phi[TSIZE-1] * (2 * phi[TSIZE-1] - phi[TSIZE-2])); 
	T = T * 0.5 / (UNIT * UNIT);//kinetic energy
	numerator = U + T;
	E0 = numerator / denominator;//starting energy
	printf("E0 = ( %f + %f ) / %f = %f\n", U, T, denominator, E0);

	for (int i = 0; i < steps; i++){
		r = (float)rand()/RAND_MAX;
		index = rand() % (TSIZE - 1);
		phiTrial = phi[index] + (r - 0.5)*dPhi;
		float deltaPhi = phiTrial - phi[index];
		float dU, dT;
		float x = indexToX(index);
		float deltaPhiSqr = phiTrial * phiTrial - phi[index] * phi[index];

		if (index == 0) dT = (deltaPhiSqr - deltaPhi * phi[index+1]) / (UNIT * UNIT);
		else if (index == TSIZE-1) dT = (deltaPhiSqr - deltaPhi * phi[index-1]) / (UNIT * UNIT);
		else dT = (deltaPhiSqr  - deltaPhi * (phi[index+1] - phi[index-1])) / (UNIT * UNIT);

		dU = deltaPhi * deltaPhi * x * x / 2;
		float newNumerator = numerator + dU + dT;
		float newDenominator = denominator + deltaPhiSqr;
		float newE = newNumerator / newDenominator;//new energy
		if (newE < E0 && newE > 0){
			phi[index] = phiTrial;
			E0 = newE;
			numerator = newNumerator;
			denominator = newDenominator;
		}
		//if (i%10000 == 0) printf(" dT:%.3f\t dU:%.4f\t step:%d\t E:%f\n", dT, dU, i, E0);
	}
	printf("E = %f\n", E0);
	return 0;
}

float indexToX(int index){
	if (index > TSIZE - 1 || index < 0){
		printf("%d - wrong index - out of scope\n", index);
		return 10;
	}
	else if (index <= TSIZE) return (-4 + index * UNIT);
	else return (4 - index * UNIT);
}
