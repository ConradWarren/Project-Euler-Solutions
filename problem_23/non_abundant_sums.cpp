#include <iostream>
#include <vector>
#include <cmath>

bool Is_Abundant(int num){
	
	int N = num;
	int idx = 2;
	int sum_of_divisors = 1;

	while(idx * idx <= num){
		
		int count = 0;
		
		while(num%idx == 0){
			num /= idx;
			count++;
		}

		if(count > 0){
			sum_of_divisors *= (std::pow(idx, count+1) - 1)/(idx - 1);
		}
		idx++;
	}
	
	if(num > 1) sum_of_divisors *= (1 + num);
	sum_of_divisors -= N;

	return sum_of_divisors > N;
}

long long Non_Abundant_Sums(){
	
	const int upper_limit = 28123;
	std::vector<bool> can_sum(upper_limit, false);
	std::vector<int> abundant_nums;
	long long result = 0;
	
	can_sum[0] = true;

	for(int i = 1; i < upper_limit; i++){
		if(Is_Abundant(i)) abundant_nums.push_back(i);
	}

	for(int i = 0; i < abundant_nums.size(); i++){
		for(int j = i; j < abundant_nums.size(); j++){
			if(abundant_nums[i] + abundant_nums[j] < upper_limit) can_sum[abundant_nums[i] + abundant_nums[j]] = true;
		}
	}

	for(int i = 0; i < upper_limit; i++){
		if(!can_sum[i]) result += i;
	}

	return result;
}

int main(void){
	
	std::cout<<Non_Abundant_Sums()<<std::endl;
	//4179871

	return 0;
}
