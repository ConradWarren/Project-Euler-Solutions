#include <iostream>
#include <vector>


long long Find_Sum_of_Valid(const std::vector<int>& factorial_values, long long current_value, long long current_sum){
	
	if(current_value >= 1000000){
		return 0;
	}
	long long result = 0;
	
	if(current_sum == current_value && current_value != 0 && current_value != 1 && current_value != 2){
		result = current_sum;
	}

	for(int i = 0; i < 10; i++){
		
		if(i == 0 && current_value == 0){
			continue;
		}
		result += Find_Sum_of_Valid(factorial_values, current_value * 10 + i, current_sum + factorial_values[i]);
	}
	
	return result;
}

long long Digit_Factorials(){

	std::vector<int> factorial_values(10, 0);
	factorial_values[0] = 1;

	for(int i = 1; i < factorial_values.size(); i++){
		factorial_values[i] = i * factorial_values[i-1];
	}
	
	return Find_Sum_of_Valid(factorial_values, 0, 0);
}


int main(void){

	std::cout<<Digit_Factorials()<<std::endl;

	return 0;
}
