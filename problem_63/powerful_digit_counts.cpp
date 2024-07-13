#include <iostream>
#include <vector>

int Get_Digit_Count(const std::vector<int>& num){
	
	int result = 0;

	for(int i = static_cast<int>(num.size()) - 1; i >= 0 && result == 0; i--){
		
		if(num[i] == 0) continue;

		int current = num[i];
		while(current){
			current /= 10;
			result++;
		}

		result += (i * 5);
	}
	
	return result;
}

void Multiply_Large_Num(std::vector<int>& large_num, int factor){
	
	const int mod = 100000;

	for(int i = static_cast<int>(large_num.size()) - 1; i >= 0; i--){	
		large_num[i] *= factor;
		if(large_num[i] >= mod){
			large_num[i+1] += large_num[i]/mod;
			large_num[i] %= mod;
		}
	} 
}

int Count_Valid_Nums(int n){
	
	int idx = 1;
	int digit_count = 0;
	int result = 0;

	while(digit_count <= n){
		
		std::vector<int> num(10, 0);
		num[0] = 1;
		for(int i = 0; i < n; i++){
			Multiply_Large_Num(num, idx);
		}
		
		digit_count = Get_Digit_Count(num);
		if(digit_count == n) result++;
		idx++;
	}

	return result;
}

int Powerful_Digit_Counts(){

	int n = 1;
	int result = 0;
	int last = -1;

	while(last != 0){
		last = Count_Valid_Nums(n);
		result += last;
		n++;
	}

	return result;
}

int main(void){

	std::cout<<Powerful_Digit_Counts()<<std::endl;
	// 49
	return 0;
}
