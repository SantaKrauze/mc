#include "src/Drunkard.hpp"
//#include "src/Drunkard.cpp"

int main(int argc, char* argv[], char* envp[]){
	int k = 10000; //number of drunkards
	long int n = atoi(argv[1]); //number of steps
	Drunkard drunkard1(n, k);
	drunkard1.printToFile();
	return 0;
}
