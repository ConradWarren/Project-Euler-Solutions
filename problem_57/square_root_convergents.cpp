#include <iostream>
#include <vector>
#include <algorithm>

int Get_Digit_Count(const std::vector<int>& num){
	
	int result = 0;
	for(int i = static_cast<int>(num.size()) - 1; i >= 0 && result == 0; i--){
		
		int current = num[i];
		while(current){
			result++;
			current /= 10;
		}

		if(num[i]) result += i * 5;	
	}	
	
	return result;
}

void Multiply_Numbers(const std::vector<int>& large_factor, int small_factor, std::vector<int>& result){
	
	const int mod = 100000;
	
	for(int i = static_cast<int>(large_factor.size()) - 1; i >= 0; i--){
		
		result[i] = large_factor[i] * small_factor;
		
		if(result[i] >= mod){
			result[i+1] += result[i]/mod;
			result[i] %= mod;
		}
	}
}

void Add_Numbers(const std::vector<int>& factor, std::vector<int>& result){

	const int mod = 100000;
	
	for(int i = 0; i < result.size(); i++){
		
		result[i] += factor[i];

		if(result[i] >= mod){
			result[i+1] += result[i]/mod;
			result[i] %= mod;
		}
	}
}

int Square_Root_Convergents(){
	
	const int upper_limit = 1000;
	std::vector<int> prev_prev_denominator(200, 0);
	std::vector<int> prev_denominator(200, 0);
	std::vector<int> denominator(200, 0);
	std::vector<int> numerator(200, 0);
	int result = 0;

	prev_prev_denominator[0] = 1;
	prev_denominator[0] = 2;

	for(int i = 2; i <= upper_limit; i++){
		
		Multiply_Numbers(prev_denominator, 2, denominator);
		Add_Numbers(prev_prev_denominator, denominator);

		std::copy(prev_denominator.begin(), prev_denominator.end(), numerator.begin());
		Add_Numbers(denominator, numerator);

		if(Get_Digit_Count(numerator) > Get_Digit_Count(denominator)) result++;
		
		std::copy(prev_denominator.begin(), prev_denominator.end(), prev_prev_denominator.begin());
		std::copy(denominator.begin(), denominator.end(), prev_denominator.begin());
		std::fill(denominator.begin(), denominator.end(), 0);
	}

	return result;
}



int main(void){
	
	std::cout<<Square_Root_Convergents()<<std::endl;
	//153
	return 0;
}
