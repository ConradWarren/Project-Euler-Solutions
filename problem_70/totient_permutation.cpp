#include <iostream>
#include <climits>
#include <vector>

int Eulers_Totient_Function(int num){
	
	if(num <= 1) return 0;

	int result = num;
	int idx = 3;
	
	if(num%2 == 0){
		result -= result/2;
	}
	while(num%2 == 0){
		num /= 2;
	}

	while(idx * idx <= num){
		
		if(num%idx == 0) result -= result/idx;

		while(num%idx == 0){
			num /= idx;
		}
		idx += 2;
	}

	if(num != 1) result -= result/num;

	return result;
}

bool Is_Permutation(int num_1, int num_2){
	
	std::vector<int> digit_count_1(10, 0);
	std::vector<int> digit_count_2(10,0);

	while(num_1){
		digit_count_1[num_1%10]++;
		num_1 /= 10;
	}

	while(num_2){
		digit_count_2[num_2%10]++;
		num_2 /= 10;
	}

	return digit_count_1 == digit_count_2;
}

int Totient_Permutation(){
	
	const int upper_limit = 10000000;
	double min_ratio = INT_MAX;
	int result = 0;

	for(int i = 2; i < upper_limit; i++){
		
		int totient = Eulers_Totient_Function(i);
		if(Is_Permutation(totient, i)){
			double ratio = static_cast<double>(i)/static_cast<double>(totient);
			if(ratio < min_ratio){
				min_ratio = ratio;
				result = i;
			}
		}
	}

	return result;
}

int main(void){
	
	std::cout<<Totient_Permutation()<<std::endl;
	//8319823
	return 0;
}
