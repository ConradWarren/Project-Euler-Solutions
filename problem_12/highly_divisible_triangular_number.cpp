#include <iostream>

int count_divisors(long long num){
	
	long long idx = 2;
	int divisor_count = 1;

	while(idx * idx <= num){

		int count = 0;

		while(num%idx == 0){
			num /= idx;
			count++;
		}

		divisor_count *= (count + 1);
		idx++;
	}

	if(num != 1) divisor_count *= 2;

	return divisor_count;
}


long long highly_divisible_triangular_number(){
	
	const int divisor_count_target = 500;
	long long triangle_number = 1;
	long long idx = 2;

	while(count_divisors(triangle_number) < divisor_count_target){
		triangle_number += idx;
		idx++;
	}

	return triangle_number;
}


int main(void){

	std::cout<<highly_divisible_triangular_number()<<std::endl;
	//76576500	
	return 0;
}
