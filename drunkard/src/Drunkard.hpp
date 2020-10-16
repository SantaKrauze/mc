#ifndef DRUNKARD_HPP
#define DRUNKARD_HPP
#include <iostream>
#include <time.h>
#include <array>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>

class Drunkard{
	public:
		Drunkard(long int n, int k);
		~Drunkard(){
			Xn.clear();
		}
		void printToFile();
		double varCalc();
	private:
		long int N, K;
		std::string filepath;
		std::ofstream data;
		std::vector<long int> Xn;
};
#endif
