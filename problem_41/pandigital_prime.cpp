#include <iostream>
#include <vector>

bool Is_Pandigital(int num){

	int current = num;
	int bit_mask = 0;
	int digit_count = 0;

	while(current){
		bit_mask |= (1 << (current%10));
		current /= 10;
		digit_count++;
	}
	
	return (bit_mask == ((1 << (digit_count+1)) - 2));
}

int Pandigital_Prime(){
	
	const int upper_limit = 1000000000;
	std::vector<bool> is_prime(upper_limit, true);
	
	is_prime[0] = false;
	is_prime[1] = false;

	for(int i = 2; i * i < upper_limit; i++){
		
		if(!is_prime[i]) continue;

		for(int j = i * i; j < upper_limit; j += i){
			is_prime[j] = false;
		}
	}

	for(int i = upper_limit - 1; i >= 0; i--){
		if(is_prime[i] && Is_Pandigital(i)){
			return i;
		}
	}
	
	return 0;
}


int main(void){

	std::cout<<Pandigital_Prime()<<std::endl;	
	//7652413 
	return 0;
}
