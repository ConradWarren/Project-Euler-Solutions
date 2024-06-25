#include <iostream>
#include <vector>
#include <cmath>

int Power_Digit_Sum(){
	
	const int power_of_two = 1000;
	
	int base_10_digit_count = (int)(power_of_two * std::log(2) + 1);
	
	std::vector<int> base_10_digit(base_10_digit_count+1, 0);
	int sum = 0;

	base_10_digit[0] = 1;
	
	for(int i = 1; i <= power_of_two; i++){
		for(int j = base_10_digit_count - 1; j >= 0; j--){
			base_10_digit[j] *= 2;
			base_10_digit[j+1] += base_10_digit[j]/10;
			base_10_digit[j] %= 10;
		}
	}

	for(int i = 0; i < base_10_digit_count; i++){
		sum += base_10_digit[i];
	}

	return sum;
}


int main(void){
	
	std::cout<<Power_Digit_Sum()<<std::endl;
	//1366
	return 0;
}
