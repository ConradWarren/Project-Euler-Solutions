#include <iostream>
#include <vector>

void Sieve_of_Eratosthenes(int upper_bound, std::vector<bool>& sieve){
	
	sieve.resize(upper_bound+1, true);

	sieve[0] = false;
	sieve[1] = false;

	for(int i = 2; i * i <= upper_bound; i++){

		if(!sieve[i]) continue;

		for(int j = i * i; j <= upper_bound; j += i){
			sieve[j] = false;	
		}
	}
}

int Get_Circular_Count(int upper_bound, int num, std::vector<bool>& is_prime){
	
	int result = 0;
	int current = num/10;
	int digit_offset = 1;
	
	while(current){
		digit_offset *= 10;
		current /= 10;
	}
	
	current = num;

	do{
		if(!is_prime[current]) return 0;
		
		is_prime[current] = false;

		if(current < upper_bound) result++;

		current = current/10 + current%10 * digit_offset;

	}while(current != num);
	
	return result;
}

int Circular_Primes(){
	
	const int upper_bound = 1000000;
	int result = 0;
	std::vector<bool> is_prime;
	
	Sieve_of_Eratosthenes(upper_bound, is_prime);
	
	for(int i = 2; i < upper_bound; i++){
		if(is_prime[i]) result += Get_Circular_Count(upper_bound, i, is_prime);
	}
	
	return result;
}


int main(void){
	
	std::cout<<Circular_Primes()<<std::endl;

	return 0;
}
