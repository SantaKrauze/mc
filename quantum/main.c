#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define TSIZE 800

float calcX(int index, float unit);
float calcV(float x);
void energyToFile(float E, int step);
void phiToFile(float phi, float x);
float set(float phi, float dphi);

int main(){
	float unit = (float) 8 / TSIZE;
	//printf("unit: %f\n",unit);
	int steps = 1000000;
        int index;
	float phiStart = 0.01;
	float dPhi = 0.1;
	float phiTrial;
	float r;
	float denominator = 0;
	float phi[TSIZE+1]; 
	float U = 0, T = 0;
	float numerator;
	float E0;
	for (int i = 0; i <= TSIZE; i++) {
		phi[i] = phiStart;
		U += (phi[i] * phi[i] * calcV( calcX(i, unit) ));//potential energy
		denominator += phi[i] * phi[i];
		//printf("phi%d= %f, V%d=%f\n",i,phi[i],i,calcV(calcX(i, unit)));
	}

	for (int i = 1; i < TSIZE; i++){
	       	T += 0.5 * phi[i] * (2 * phi[i] - phi[i-1] - phi[i+1]);
		//printf("t=%f\n",T);
	}
	T +=0.5*phi[0] * (2 * phi[0] - phi[1]);
	//printf("t=%f\n",T);
	T += 0.5*phi[TSIZE] * (2 * phi[TSIZE] - phi[TSIZE-1]);
	//printf("f1=%f f2=%f\n",phi[TSIZE],phi[TSIZE-1]);
	//printf("t=%f",T);
	T = T / (unit * unit);//kinetic energy
	numerator = U + T;
	E0 = numerator / denominator;//starting energy
	printf("E0 = (%f+%f)/%f = %f\n", U, T, denominator, E0);
	float deltaPhi, dU,dT, deltaPhiSqr, newE;

	for (int i = 0; i <= steps; i++){
		r = (float)rand()/RAND_MAX;
		index = rand() % TSIZE;
		//printf("r=%f, index=%d\n",r,index);
		phiTrial = phi[index] + (r - 0.5)*dPhi;
		deltaPhi = phiTrial - phi[index];
		//printf("dp:%f=%f-%f\n",deltaPhi,phiTrial,phi[index]);
		deltaPhiSqr = (phiTrial * phiTrial) - (phi[index] * phi[index]);
		//printf("dp2:%f=%f-%f\n",deltaPhiSqr,phiTrial*phiTrial,phi[index]*phi[index]);

		if (index == 0) dT = (deltaPhiSqr - (deltaPhi * phi[index+1]));
		else if (index == TSIZE) dT = (deltaPhiSqr - (deltaPhi * phi[index-1]));
		else dT = (deltaPhiSqr  - deltaPhi * (phi[index+1] + phi[index-1]));
		dT = dT / (unit*unit);

		dU = deltaPhiSqr * calcV( calcX(index, unit) );
		//printf("dU=%f, dT=%f\n",dU,dT);
		newE = (numerator + dU + dT) / (denominator + deltaPhiSqr);//new energy
		if (newE < E0 && newE > 0){
			phi[index] = phiTrial;
			E0 = newE;
			numerator += dU + dT;
			denominator += deltaPhiSqr;
			//printf("E:%f - MCS:%d\n",E0, i);
		}
		//energyToFile(E0, i);
	}
	for (int i = 0; i <= TSIZE;i++){
		//phiToFile(phi[i], calcX(i, unit) );
	}
	printf("E = %f\n", E0);
	return 0;
}

void phiToFile(float phi, float x){
	FILE *file;
	file = fopen("phi.dat","a+");
	fprintf(file,"%f\t%f\n",x, phi);
	fclose(file);
}

void energyToFile(float E, int step){
	FILE *file;
	file = fopen("energy.dat","a+");
	fprintf(file, "%f\t%d\n",step, E);
	fclose(file);
}

float calcV (float x){
	return 0.5*x*x;
}

float calcX(int index, float unit){
	if (index > TSIZE || index < 0){
		printf("%d - wrong index - out of scope\n", index);
		return 10;
	}
	else return (-4 + (index * unit));
}
