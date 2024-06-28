#include <iostream>
#include <cmath>

long long Digit_Fifth_Power(){
	
	const int upper_limit = 6;
	long long result = 0;
	
	for(int i = std::pow(10,upper_limit+1)-1; i > 1; i--){
		
		int num = i;
		int sum = 0;

		while(num > 0){
			sum += std::pow(num%10, 5);
			num /= 10;
		}

		if(sum == i){
			result += sum;
		}
	}
	
	return result;
}


int main(void){
	
	std::cout<<Digit_Fifth_Power()<<std::endl;

	return 0;
}
