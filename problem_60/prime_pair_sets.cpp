#include <iostream>
#include <vector>
#include <string>
#include <climits>

bool Is_Prime(long long num){
	
	if(num == 2 || num == 3) return true;

	if(num == 1 || num%2 == 0) return false;

	if((num + 1)%6 != 0 && (num - 1)%6 != 0) return false;

	long long idx = 3;

	while(idx * idx <= num){
		if(num%idx == 0) return false;
		idx += 2;
	}
	
	return true;
}

int Find_Smallest_Sum(const std::vector<int>& primes, int idx, std::vector<int>& current,const std::vector<bool>& is_prime){
	
	if(current.size() >= 5){
		return 0;
	}
	
	if(idx >= primes.size()) return 1e9;

	bool can_take = true;

	for(int i = 0; i < current.size() && can_take; i++){
		
		long long num_1 = std::stoll(std::to_string(current[i]) + std::to_string(primes[idx]));
		long long num_2 = std::stoll(std::to_string(primes[idx]) + std::to_string(current[i]));
		
		if(!Is_Prime(num_1) || !Is_Prime(num_2)) can_take = false; 	
	}
	
	current.push_back(primes[idx]);
	int take = (can_take) ? primes[idx] + Find_Smallest_Sum(primes, idx+1, current, is_prime) : INT_MAX;
	current.pop_back();
	int skip = Find_Smallest_Sum(primes, idx+1, current, is_prime);

	return (take < skip) ? take : skip;
}

int Prime_Pair_Sets(){

	const int upper_bound = 10000;
	std::vector<bool> is_prime(upper_bound, true);
	std::vector<int> primes;

	is_prime[0] = false;
	is_prime[1] = false;

	for(long long i = 0; i * i < upper_bound; i++){
		

		for(long long j = i * i; is_prime[i] && j < upper_bound; j += i){
			is_prime[j] = false;
		}
	}
	
	for(int i = 0; i < upper_bound; i++){
		if(is_prime[i]) primes.push_back(i);
	}

	std::vector<int> current;
	return Find_Smallest_Sum(primes, 0, current, is_prime);
}

int main(void){

	std::cout<<Prime_Pair_Sets()<<std::endl;
	//26033 
	return 0;
}
