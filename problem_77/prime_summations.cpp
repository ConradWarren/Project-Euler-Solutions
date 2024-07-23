#include <iostream>
#include <vector>

int Prime_Summations(){
	
	const int upper_limit = 1000000;
	const int target = 5000;
	int result = upper_limit;
	std::vector<int> ways(upper_limit+1, 0);
	std::vector<int> primes;
	std::vector<bool> is_prime(upper_limit+1, true);
	
	is_prime[0] = false;
	is_prime[1] = false;

	for(int i = 0; i * i <= upper_limit; i++){
		
		if(!is_prime[i]) continue;
		
		for(int j = i*i; j <= upper_limit; j += i){
			is_prime[j] = false;
		}
	}
	
	for(int i = 0; i <= upper_limit; i++){
		if(is_prime[i]) primes.push_back(i);
	}
	
	ways[0] = 1;
	for(int i = 0; i < primes.size(); i++){
		for(int j = 0; j + primes[i] < result; j++){
			ways[j+primes[i]] += ways[j];
			if(ways[j+primes[i]] >= target) result = j + primes[i];
		}
	}

	return result;
}

int main(void){
	
	std::cout<<Prime_Summations()<<std::endl;
	//71
	return 0;
}
