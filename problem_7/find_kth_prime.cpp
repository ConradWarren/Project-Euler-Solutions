#include <iostream>
#include <cmath>
#include <vector>

int estimate_upper_bound(int prime_idx){
	
	if(prime_idx < 6) return 13;

	return prime_idx * (int)(std::log(prime_idx) + std::log(std::log(prime_idx)));
}

void Sieve_of_Eratosthenes(int upper_bound, std::vector<bool>& sieve){
	
	sieve[0] = false;
	sieve[1] = false;

	for(int i = 2; i <= upper_bound; i++){
		
		if(!sieve[i]) continue;
		
		for(int j = i * 2; j <= upper_bound; j += i){
			sieve[j] = false;
		}
	}
}

int Find_Kth_Prime(){

	const int k = 10001;
	
	int count = 0;
	int upper_bound = estimate_upper_bound(k);
	std::vector<bool> is_prime(upper_bound + 1, true);
	
	Sieve_of_Eratosthenes(upper_bound, is_prime);

	for(int i = 0; i <= upper_bound; i++){
		
		if(is_prime[i]) count++;
		
		if(count == k) return i;
	}

	return -1;
}


int main(void){

	std::cout<<Find_Kth_Prime()<<std::endl;
	//104743

	return 0;
}
