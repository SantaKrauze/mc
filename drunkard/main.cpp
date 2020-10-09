#include "src/Drunkard.hpp"
//#include "src/Drunkard.cpp"

int main(){
	int k = 10000; //number of drunkards
	long int n = 100; //number of steps
	Drunkard drunkard1(n, k);
	std::cout<<"var: "<<drunkard1.varCalc()<<std::endl;
	Drunkard drunkard2(10*n, k);
	std::cout<<"var: "<<drunkard2.varCalc()<<std::endl;
	Drunkard drunkard3(100*n, k);
	std::cout<<"var: "<<drunkard3.varCalc()<<std::endl;
	Drunkard drunkard4(1000*n, k);
	std::cout<<"var: "<<drunkard2.varCalc()<<std::endl;
	//Drunkard drunkard5(10000*n, k);
	//std::cout<<"var: "<<drunkard3.varCalc()<<std::endl;
	return 0;
}
