#include <iostream>
#include <cmath>

int Nth_Digit_Fibonacci_Number(){

	const int target_digit = 1000;
	const double phi = 1.6180339887;
	
	return (static_cast<double>(target_digit) - 0.5 * std::log10(5.0))/std::log10(phi) - 1;
}


int main(void){
	
	std::cout<<Nth_Digit_Fibonacci_Number()<<std::endl;
	//4782
	return 0; 
}
