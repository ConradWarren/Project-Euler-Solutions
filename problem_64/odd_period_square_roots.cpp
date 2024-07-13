#include <iostream>
#include <unordered_map>
#include <map>
#include <cmath>
#include <numeric>
#include <vector>

int Get_Sequence_Length(int num){
	
	std::map<std::vector<long long>, int> sequence_map;
	double current_num = std::sqrt(num);
	long long a = static_cast<int>(current_num);
	int sequence_length = 0;
	int idx = 0;
	long long numerator = 1;
	long long denominator = -a;
	long long factor = 1;
	
	while(sequence_length == 0){
		
		long long rationalized_denominator = num * factor * factor + denominator * denominator * -1;
		factor *= numerator;
		numerator *= -denominator;
		
		a = (std::sqrt(num) * static_cast<double>(factor) + numerator)/static_cast<double>(rationalized_denominator);
		
		numerator -= a * rationalized_denominator;
		
		int gcd = std::gcd(std::gcd(numerator, factor), rationalized_denominator);

		numerator /= gcd;
		factor /= gcd;
		rationalized_denominator /= gcd;

		std::vector<long long> id = {a, factor, numerator, rationalized_denominator};	

		if(sequence_map.find(id) == sequence_map.end()){
			sequence_map[id] = idx;
			idx++;
		}else{
			sequence_length = idx - sequence_map[id];
		}

		denominator = numerator;
		numerator = rationalized_denominator;
	}


	return sequence_length;
}



int Odd_Period_Square_Roots(){
	
	const int upper_limit = 10000;
	int result = 0;

	for(int i = 2; i <= upper_limit; i++){
		
		int square = std::sqrt(i);
		if(square * square == i) continue;

		int length = Get_Sequence_Length(i);
		if(length%2 == 1) result++;
	}

	return result;
}

int main(void){

	std::cout<<Odd_Period_Square_Roots()<<std::endl;
	//1322

	return 0;
}
