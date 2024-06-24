#include <iostream>
#include <vector>

long long summation_of_primes(){
	
	const int upper_bound = (int)2e6;
	std::vector<bool> sieve(upper_bound + 1, true);
	long long sum = 0;

	for(int i = 2; i <= upper_bound; i++){
		
		if(!sieve[i]) continue;

		sum += i;
		
		for(int j = i * 2; j <= upper_bound; j += i){
			sieve[j] = false;
		}
	}

	return sum;
}


int main(void){
	
	std::cout<<summation_of_primes()<<std::endl;
	//142913828922
	return 0;
}
