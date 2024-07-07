#include <iostream>
#include <vector>
#include <unordered_set>

bool Is_Prime(int num){
	
	if(num == 2 || num == 3) return true;
	
	if(num%2 == 0 || num <= 1) return false;
	
	if((num - 1)%6 != 0 && (num + 1)%6 != 0) return false; 
	
	int idx = 3;

	while(idx * idx <= num){
		if(num%idx == 0) return false;
		idx += 2;
	}

	return true;
}

bool Is_Truncatable(int num, std::unordered_set<int>& cache){

	int digit_offset = 1;
	int left_to_right_num = 0;
		
	while(num){

		if(cache.find(num) == cache.end() && !Is_Prime(num)){
			return false;
		}
		cache.insert(num);
		
		if(left_to_right_num != 0 && cache.find(left_to_right_num) == cache.end() && !Is_Prime(left_to_right_num)){
			return false;
		}
		if(left_to_right_num != 0) cache.insert(left_to_right_num);

		left_to_right_num += (num%10) * digit_offset;
		num /= 10;
		digit_offset *= 10;
	}

	return true;
}


int Truncatable_Primes(){

	std::unordered_set<int> prime_cache;
	int result = 0;
	
	for(int i = 11; i < 1000000; i++){
		if(Is_Truncatable(i, prime_cache)){
			result += i;
		}
	}
	
	return result;
}

int main(void){
	
	std::cout<<Truncatable_Primes()<<std::endl;	


	return 0;
}
