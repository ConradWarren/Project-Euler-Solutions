#include <iostream>
#include <vector>

void Eratosthenes_Sieve(int upper_limit, std::vector<bool>& sieve){
	
	sieve.resize(upper_limit + 1, true);
	sieve[0] = false;
	sieve[1] = false;

	for(int i = 2; i <= upper_limit; i++){

		if(!sieve[i]) continue;

		for(int j = i * 2; j <= upper_limit; j += i){
			sieve[j] = false;
		}  
	}
}

int Get_Prime_Sequence_Length(int a, int b, std::vector<bool>& is_prime){

	int n = 0;
	int value = n * n + a * n + b;

	while(value >= 0 && is_prime[value]){
		n++;
		value = n*n + a*n + b;
	}

	return n;
}

int Quadratic_Primes(){

	std::vector<bool> is_prime;
	int longest_sequence = 0;
	int result = 0;

	Eratosthenes_Sieve(1e6, is_prime);

	for(int a = -1000; a <= 1000; a++){
		for(int b = -1000; b <= 1000; b++){
			int sequence_length = Get_Prime_Sequence_Length(a, b, is_prime);
			if(sequence_length > longest_sequence){
				longest_sequence = sequence_length;
				result = a * b;
			}
		} 
	} 

	return result;
}

int main(void){
	
	std::cout<<Quadratic_Primes()<<std::endl;	
	//-59231
	return 0;
}
