#include <iostream>
#include <vector>

void Add_Large_Numbers_Times_Constant(const std::vector<int>& factor_1, int factor_2, std::vector<int>& result){
	
	const int mod = 1000;

	for(int i = 0; i < result.size(); i++){
		result[i] += factor_1[i] * factor_2;
		if(result[i] >= mod){
			result[i+1] += result[i]/mod;
			result[i] %= mod;
		}
	}
}

int Get_Digit_Sum(const std::vector<int>& large_num){
	
	int result = 0;
	for(int i = 0; i < large_num.size(); i++){
		
		int current = large_num[i];
		while(current){
			result += current%10;
			current /= 10;
		}
	}
	
	return result;
}

long long Convergents_of_e(){
	
	const int target = 100;
	std::vector<int> numerator(100, 0);
	std::vector<int> denomirator(100, 0);

	denomirator[0] = 1;

	for(int i = target-1; i > 0; i--){
		
		int k = (i%3 == 2) ? (2 * (i/3 + 1)) : 1;
		Add_Large_Numbers_Times_Constant(denomirator, k, numerator);

		std::swap(numerator, denomirator);

	}
	
	Add_Large_Numbers_Times_Constant(denomirator, 2, numerator);
	
	return Get_Digit_Sum(numerator);
}

int main(void){
	
	std::cout<<Convergents_of_e()<<std::endl;
	//272	

	return 0;
}
