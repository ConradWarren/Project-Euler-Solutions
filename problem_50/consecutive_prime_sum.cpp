#include <iostream>
#include <climits>
#include <vector>

int Consecutive_Prime_Sum(){
	
	const int upper_limit = 1000000;
	std::vector<bool> is_prime(upper_limit, true);
	std::vector<int> primes;
	int result = 0;
	int most_primes = 0;

	is_prime[0] = false;
	is_prime[1] = false;
	
	for(int i = 0; i < upper_limit; i++){
		
		if(!is_prime[i]) continue;
		
		primes.push_back(i);

		for(long long j = static_cast<long long>(i) * i; j < upper_limit; j += i){
			is_prime[j] = false;
		}
	}
	
	for(int i = 0; i < primes.size(); i++){
		
		int current_sum = primes[i];

		for(int j = i + 1; j < primes.size() && current_sum < upper_limit; j++){
			
			current_sum += primes[j];

			if(current_sum < upper_limit && j - i + 1 > most_primes && is_prime[current_sum]){
				result = current_sum;
				most_primes = j - i + 1;
			}
		}
	}
	
	return result;
}

int main(void){
	
	std::cout<<Consecutive_Prime_Sum()<<std::endl;
	//997651	
	return 0;
}
