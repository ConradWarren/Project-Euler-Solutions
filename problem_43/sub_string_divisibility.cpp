#include <iostream>
#include <vector>

long long Find_Sub_String_Sum(int bitmask, int idx, long long num, const std::vector<int>& divisors){

	int last_three_digits = num%1000;
	
	if(last_three_digits%divisors[idx] != 0){
		return 0;
	}

	if(idx >= 10){
		return num;
	}

	long long result = 0;
	for(int i = (idx != 0) ? 0 : 1; i <= 9; i++){
		if(!(bitmask & (1 << i))){
			result += Find_Sub_String_Sum(bitmask | (1 << i), idx+1, num * 10 + i, divisors);
		}
	}

	return result;
}

long long Sub_String_Divisibility(){
	
	const std::vector<int> divisors = {1,1,1,1,2,3,5,7,11,13,17};
	long long result = Find_Sub_String_Sum(0, 0, 0, divisors);
	

	return result;
}

int main(void){
	
	std::cout<<Sub_String_Divisibility()<<std::endl;
	//16695334890
	return 0;
}
