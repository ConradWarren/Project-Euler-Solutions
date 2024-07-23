#include <iostream>
#include <vector>

long long Count_Ways(int n, std::vector<int>& cache){
	
	if(n <= 1) return cache[n] = 1;
	
	int result = 1;
	for(int i = n; i > 1; i--){
		
		int remaining = n - i;
		
		if(remaining <= i){
			result += Count_Ways(remaining, cache);
		}else{
			result += Count_Ways(i, cache) * (remaining/i);
		}
	}

	return cache[n] = result;
}

long long test(int coins_left, int limit){
	
	if(limit == 1){
		return 1;
	}
	
	return coins_left/limit + test(coins_left, limit-1);
}

int Coin_Partitions(){
	
	const int target = 1000000;
	const int upper_limit = 100000;
	long long count = 0;
	int idx = 0;
	std::vector<long long> ways(upper_limit+1, 0);
	ways[0] = 1;

	for(int i = 1; i <= upper_limit; i++){
		for(int j = 0; j + i < ways.size(); j++){
			ways[j+i] += ways[j];
			ways[j+i] %= target;
		}
		if(ways[i] % target == 0) return i;
	}
	
	return -1;
}

int main(void){
	
	std::cout<<Coin_Partitions()<<std::endl;
	//55374
	return 0;
}
