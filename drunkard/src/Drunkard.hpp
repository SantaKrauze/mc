#ifndef DRUNKARD_HPP
#define DRUNKARD_HPP
#include <iostream>
#include <time.h>
#include <array>
#include <vector>
#include <stdlib.h>
#include <math.h>

class Drunkard{
	public:
		Drunkard(long int n, int k);
		void printToFile();
		double varCalc();
	private:
		long int N, K;
		std::vector<long int> Xn;
};
#endif
