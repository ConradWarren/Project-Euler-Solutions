#include <iostream>
#include <cmath>

int Find_Largest_Pandigital_Multiple(int n){

	int num = 1;
	int result = 0;
	int max_digit_count = 0;
	int target_bitmask = (1 << 10) - 2;
	int upper_limit = std::pow(10, 10/n) - 1;

	while(num <= upper_limit){
		
		int multiple = 0;
		bool is_valid = true;
		int bitmask = 0;

		for(int i = 1; i <= n && is_valid; i++){
			
			int current = num * i;
			int digit_offset = 1;
			
			while(current){
				
				if(current%10 == 0 || (bitmask & (1 << (current%10)))){
					is_valid = false;
					break;
				}

				bitmask |= (1 << (current%10));
				current /= 10;
				digit_offset *= 10;
			}
			
			multiple *= digit_offset;
			multiple += num * i;
		} 
		
		if(is_valid && bitmask == target_bitmask){
			result = (result > multiple) ? result : multiple;
		}
		num++;
	}
	
	return result;
}



int Pandigital_Multiples(){
	
	int result = 0;
	
	for(int n = 2; n <= 9; n++){
		
		int current = Find_Largest_Pandigital_Multiple(n);
		result = (result > current) ? result : current;
	}
	
	return result;
}

int main(void){
	
	std::cout<<Pandigital_Multiples()<<std::endl;
	//932718654
	
	return 0;
}
