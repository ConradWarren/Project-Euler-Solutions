#include <iostream>
#include <vector>

int Get_Digit_Sum(const std::vector<long long>& num){

	int sum = 0;
	
	for(int i = 0; i < num.size(); i++){
		
		long long current = num[i];

		while(current){
			sum += current%10;
			current /= 10;
		}
	}
	
	return sum;
}

void Multiply_Large_Number(std::vector<long long>& num, int factor){
	
	const int mod = 10000;	

	for(int i = num.size() - 1; i >= 0; i--){
		
		num[i] *= factor;
		if(num[i] >= mod){
			num[i+1] += num[i]/mod;
			num[i] %= mod;
		}
	}
}

int Powerful_Digit_Sum(){
	
	const int upper_limit = 100;
	int result = 0;

	for(int base = 1; base <= upper_limit; base++){
		
		std::vector<long long> num(200, 0);
		num[0] = 1;

		for(int exp = 1; exp <= upper_limit; exp++){
			Multiply_Large_Number(num, base);

			int sum = Get_Digit_Sum(num);

			result = (result > sum) ? result : sum;
		}
		

	}
	
	return result;
}


int main(void){
		
	std::cout<<Powerful_Digit_Sum()<<std::endl;
	//972
	

	return 0;
}
