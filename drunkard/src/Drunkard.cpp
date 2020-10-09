#include "Drunkard.hpp"

Drunkard::Drunkard(long int n, int k){
	K = k;
	N = n;
	long int x;
	float r;
	std::cout<<K<<" drunks, "<<N<<" steps each\n";
	for (int i = 0; i < K; i++){//iterating drunks
		x = 0;
		for (long int j = 0; j < N; j++){//iterating steps
			r = (float)rand()/RAND_MAX;
			if (r > 0.5){
				x = x + 1;
				//std::cout<<"r:"<<r<<"\t x:"<<x<<std::endl;
			}
			else{
				x = x - 1;
				//std::cout<<"r:"<<r<<"\t x:"<<x<<std::endl;
			}	
		}
		Xn.push_back(x);
		//std::cout<<"Xk:"<<Xk.at(i-1)<<std::endl;
	}
}

void Drunkard::printToFile(){
}

double Drunkard::varCalc(){
	double sqrAvgs = 0;//square of averages
	double avgSqrs = 0;//average of squares
	for (int i = 0; i < K; i++){
		sqrAvgs += Xn.at(i);
		avgSqrs += Xn.at(i) * Xn.at(i);
	}
	sqrAvgs = sqrAvgs / K;
	sqrAvgs = sqrAvgs * sqrAvgs;
	avgSqrs = avgSqrs / K;
	return sqrt(avgSqrs - sqrAvgs);
}
