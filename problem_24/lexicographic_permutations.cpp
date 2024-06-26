#include <iostream>
#include <vector>
#include <string>

unsigned long long Factorial(int num){
	
	unsigned long long result = 1;
	for(int i = 1; i <= num; i++){
		result *= i;
	}
	return result;
}

std::string Lexicrographic_Permutations(){
	
	std::vector<char> sequence = {'0','1','2','3','4','5','6','7','8','9'};
	unsigned long long target_sequence = 999999;
	int n = sequence.size();
	std::string result;

	for(int i = n; i > 0; i--){
		unsigned long long fac = Factorial(i - 1);
		int idx = target_sequence / fac;
		result += sequence[idx];
		sequence.erase(sequence.begin() + idx);
		target_sequence %= fac;
	}

	return result;
}

int main(void){

	std::cout<<Lexicrographic_Permutations()<<std::endl;
	//2783915460
	return 0;
}
