#include <iostream>
#include <unordered_set>

bool Is_Prime(int num){

	if(num == 2 || num == 3) return true;

	if(num <= 1 || num % 2 == 0) return false;

	if((num + 1)%6 != 0 && (num - 1)%6 != 0) return false;

	int idx = 3;

	while(idx * idx <= num){
		
		if(num % idx == 0) return false;
		idx += 2;
	}
	
	return true;
}

int Goldbachs_Conjecture(){
	
	std::unordered_set<int> prime_cache;
	int result = 0;
	int num = 3;

	prime_cache.insert(2);

	while(result == 0){
		
		if(prime_cache.find(num) != prime_cache.end()){
			num += 2;
			continue;
		}
		
		if(Is_Prime(num)){
			prime_cache.insert(num);
			num += 2;
			continue;
		}
		
		int idx = 1;

		while(2 * idx * idx <= num){
			
			int prime_candidate = num - 2 * idx * idx;
			
			if(prime_cache.find(prime_candidate) != prime_cache.end()){
				break;
			}
			idx++;
		}

		if(2 * idx * idx > num){
			result = num;
		}
		num += 2;
	}
	
	return result;
}

int main(void){
	
	std::cout<<Goldbachs_Conjecture()<<std::endl;	
	//5777
	return 0;
}
