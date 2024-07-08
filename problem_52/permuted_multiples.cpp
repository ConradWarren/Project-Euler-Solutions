#include <iostream>
#include <vector>

bool Is_Valid(long long num, int target_multiple){

	std::vector<int> digit_counts(10, 0);
	std::vector<int> current_digits(10);

	long long current_num = num;
	
	while(current_num){
		digit_counts[current_num%10]++;
		current_num /= 10;
	}
	for(int i = 2; i <= target_multiple; i++){
		
		std::fill(current_digits.begin(), current_digits.end(), 0);
		current_num = num * i;
		while(current_num){
			if(++current_digits[current_num%10] > digit_counts[current_num%10]) return false;
			current_num /= 10;
		}
	}
	
	return true;
}

int Permuted_Multiples(){
	
	const int upper_bound = 1000000;
	const int target_multiple = 6;
	int result = -1;
	
	for(int i = 1; i <= upper_bound && result == -1; i++){
		if(Is_Valid(i, target_multiple)){
			result = i;
		}
	}
	
	return result;
}

int main(void){
	
	std::cout<<Permuted_Multiples()<<std::endl;
	//142857
	return 0;
}
