#include "src/Drunkard.hpp"
//#include "src/Drunkard.cpp"

int main(int argc, char* argv[], char* envp[]){
	int k = 10000; //number of drunkards
	long int n = atoi(argv[1]); //number of steps
	//std::cout<<n<<std::endl;
	Drunkard drunkard1(n, k);
	drunkard1.printToFile();
	//Drunkard drunkard2(5*n, k);	
	//drunkard2.printToFile();
	/*Drunkard drunkard3(10*n, k);
	drunkard3.printToFile();*/
	/*Drunkard drunkard4(n, k);
	std::cout<<"var: "<<drunkard2.varCalc()<<std::endl;
	Drunkard drunkard5(n, k);
	std::cout<<"var: "<<drunkard3.varCalc()<<std::endl;*/
	return 0;
}
