#include <iostream>
#include <vector>
#include <climits>


void Add_Large_Numbers(std::vector<unsigned long long>& num_1, std::vector<unsigned long long>& num_2){
	
	for(int i = (int)num_1.size() - 1; i > 0; i--){
		num_1[i] += num_2[i];
		num_1[i-1] += num_1[i]/10000000000LL;
		num_1[i] %= 10000000000LL;
	} 
}

void Multiply_Large_Number(std::vector<unsigned long long>& num, unsigned long long constant){

	
	for(int i = 0; i < num.size(); i++){
		num[i] *= constant;
		if(i != 0) num[i-1] += num[i]%10000000000LL;
		num[i] %= 10000000000LL;
	}

}

long long Self_Powers(){
	
	std::vector<unsigned long long> sum(500, 0LL);
	std::vector<unsigned long long> current(500, 0LL);
	const int upper_limit = 1000;

	for(int i = 1; i <= upper_limit; i++){
		
		std::fill(current.begin(), current.end(), 0);
		current.back() = 1;

		for(int j = 0; j < i; j++){
			Multiply_Large_Number(current, i);
		}
		Add_Large_Numbers(sum, current);
	}
	
	return sum.back();
}

int main(void){

	std::cout<<Self_Powers()<<std::endl;
	//9110846700
	return 0;
}
