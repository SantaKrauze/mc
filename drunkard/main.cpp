#include "src/Drunkard.hpp"
//#include "src/Drunkard.cpp"

int main(){
	int k = 300; //number of drunkards
	long int n = 1000; //number of steps
	Drunkard drunkard1(n, k);
	std::cout<<"var: "<<drunkard1.varCalc()<<std::endl;
	/*Drunkard drunkard2(n, k);
	std::cout<<"var: "<<drunkard2.varCalc()<<std::endl;
	Drunkard drunkard3(n, k);
	std::cout<<"var: "<<drunkard3.varCalc()<<std::endl;
	Drunkard drunkard4(n, k);
	std::cout<<"var: "<<drunkard2.varCalc()<<std::endl;
	Drunkard drunkard5(n, k);
	std::cout<<"var: "<<drunkard3.varCalc()<<std::endl;*/
	return 0;
}
