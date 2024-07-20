#include <iostream>
#include <vector>


int Get_Cycle_Length(long long num,const std::vector<int>& factorial, std::vector<bool>& cache){
	
	if(num >= cache.size()){
		std::cerr<<"Test Failed at "<<num<<std::endl;
		return 0;
	}
	
	if(cache[num]){
		return 0;
	}
	cache[num] = true;
	long long next_num = 0;
	long long current = num;
	
	while(current){
		next_num += factorial[current%10];
		current /= 10;
	}

	int cycle_length = 1+Get_Cycle_Length(next_num, factorial, cache);

	cache[num] = false;
	return cycle_length;
}

int Digit_Factorial_Chains(){

	const int target = 60;
	const int upper_limit = 1000000;
	int result = 0;
	std::vector<int> factorial(10);
	std::vector<bool> cache(upper_limit*10, false);
	

	factorial[0] = 1;
	for(int i = 1; i < 10; i++){
		factorial[i] = factorial[i-1] * i;
	}
	
	for(int i = 1; i < upper_limit; i++){
		if(Get_Cycle_Length(i, factorial, cache) == target) result++;
	}

	return result;
}

int main(void){
	
	std::cout<<Digit_Factorial_Chains()<<std::endl;
	//402 
	return 0;
}
