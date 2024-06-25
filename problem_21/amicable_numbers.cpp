#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

//d(n) = sum of divisors of n.
//
//d(a) == d(b) where a != b, a and b are amicable numbers.

int Sum_of_Divisors(int num){
	
	
	int idx = 2;
	int result = 1;
	int N = num;

	while(idx * idx <= num){
		
		int count = 0;

		while(num % idx == 0){
			num /= idx;
			count++;
		}

		if(count > 0){
			int test = 0;
			int base = 1;
			for(int i = 0; i <= count; i++){
				test += base;
				base *= idx;
			}
			
			result *= test;
		}
		idx++;
	}
	if(num != 1) result *= (num + 1);

	return result - N;
}


int Amicable_Numbers(){

	const int upper_limit = 10000;
	std::unordered_map<int, int> sum_of_divisors_map;
	int result = 0;

	for(int i = 1; i < upper_limit; i++){
		int divisor_sum = Sum_of_Divisors(i);
		if(sum_of_divisors_map.find(divisor_sum) != sum_of_divisors_map.end() && sum_of_divisors_map[divisor_sum] == i){
			result += divisor_sum;
			result += i;
		}

		sum_of_divisors_map[i] = divisor_sum;
	}
	
	return result;
}

int main(void){

	std::cout<<Amicable_Numbers()<<std::endl;
	//31626
	return 0;
}
