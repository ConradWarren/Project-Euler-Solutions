#include <iostream>
#include <cmath>
#include <climits>

inline long long P(int n){
	return (3LL * n * n - n)/2;
}

bool Is_Triangle(long long num){
	
	num *= 2;
	long long x = 1 + 4 * num;
	long long sqrt_x = std::sqrt(x);

	return (sqrt_x * sqrt_x == x && (sqrt_x-1)%2 == 0);
}

bool Is_Hexagonal(long long num){
	
	long long x = 1 + 8 * num;
	long long sqrt_x = std::sqrt(x);

	return (sqrt_x * sqrt_x == x && (sqrt_x + 1)%4 == 0);
}

long long Triangular_Pentagonal_Hexagonal(){
	
	int idx = 166;
	long long num = P(166);
	
	while(!Is_Triangle(num) || !Is_Hexagonal(num)){
		num = P(++idx);
	}

	return num;
}

int main(void){

	std::cout<<Triangular_Pentagonal_Hexagonal()<<std::endl;

	//1533776805	
	
	return 0;
}
