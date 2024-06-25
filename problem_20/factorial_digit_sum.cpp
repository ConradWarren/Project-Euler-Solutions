#include <iostream>
#include <vector>

int factorial_digit_sum(){
	
	const int factorial = 100;
	int result = 0;
	int num_size = 100;
	std::vector<int> num_base_1000(num_size + 1, 0);

	num_base_1000[0] = 1;

	for(int i = 2; i <= factorial; i++){
		for(int j = num_size - 1; j >= 0; j--){
			num_base_1000[j] *= i;
			num_base_1000[j+1] += num_base_1000[j]/1000;
			num_base_1000[j] %= 1000;
		}
	}
	
	for(int i = 0; i < num_base_1000.size(); i++){
		
		int num = num_base_1000[i];
		while(num > 0){
			result += num%10;
			num /= 10;
		}
	}

	return result;
}

int main(void){
	
	std::cout<<factorial_digit_sum()<<std::endl;
	//648  
	return 0;
}
