#include <iostream>

long long largest_prime_factor(long long n){

	long long result = 0;
	long long idx = 2;
	
	while(idx * idx <= n){
		
		if(n % idx == 0) result = idx;
		
		while(n % idx == 0){
			n /= idx;
		}

		idx++;
	}
	
	result = (result > n) ? result : n;

	return result;
}


int main(void){
	
	std::cout<<largest_prime_factor(600851475143LL)<<'\n';
	//6857
	return 0;
}
