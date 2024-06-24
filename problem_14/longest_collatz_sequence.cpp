#include <iostream>
#include <unordered_map>

int Count_Sequence_Length(long long n, std::unordered_map<long long, int>& cache){
	
	if(n == 1){
		return 1;
	}
		
	if(cache.find(n) != cache.end()){
		return cache[n];
	}

	return cache[n] = (n % 2 == 0) ? 1 + Count_Sequence_Length(n/2, cache) : 1 + Count_Sequence_Length(3 * n + 1, cache);
}


int Longest_Collatz_Sequence(){

	const int upper_bound = 1000000;
	int result = 0;
	int longest_sequence_length = 0;
	std::unordered_map<long long, int> cache;

	for(int i = 1; i < upper_bound; i++){
		int sequence_length = Count_Sequence_Length(i, cache);
		if(sequence_length > longest_sequence_length){
			result = i;
			longest_sequence_length = sequence_length;
		}
	} 
	
	return result;
}


int main(void){

	std::cout<<Longest_Collatz_Sequence()<<std::endl;
	//837799

	return 0;
}
