#include <iostream>

long long sum_to_n_squared(int n){
	return (long long)((n * (n + 1))/2) * (long long)((n * (n + 1))/2);
}

long long sum_of_squares(int n){
	return (long long)((n*(n+1))/2) * (long long)((2*n +1)/3);
}

long long sum_square_difference(){
	
	const int n = 100;

	return sum_to_n_squared(n) - sum_of_squares(n);
}


int main(void){
	
	std::cout<<sum_square_difference()<<std::endl;
	//25164150 

	return 0;
}
