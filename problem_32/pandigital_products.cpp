#include <iostream>
#include <string>
#include <algorithm>

bool Is_Valid(long long a, long long b, long long product){

	if(a * b != product) return false;


	return true;
}

long long Pandigital_Products(){
	
	
	std::string permutation = "123456789";
	std::string starting_point = permutation;

	do{

		std::next_permutation(permutation.begin(), permutation.end());
	}while(permutation != starting_point);


	return 0;
}


int main(void){


	return 0;
}
