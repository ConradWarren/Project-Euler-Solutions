#include <iostream>

long long GCD(long long a, long long b){
	while(b > 0){
		long long temp = a;
		a = b;
		b = temp%b;
	}
	return a;
}

long long LCM(long long a, long long b){
	return (a * b)/GCD(a, b);
}

int smallest_multiple(){

	const int limit = 20;
	int current_multiple = 1;
	
	for(int num = 2; num <= limit; num++){
		current_multiple = LCM(current_multiple, num);
	}

	return current_multiple;
}

int main(void){
	
	std::cout<<smallest_multiple()<<std::endl;
	//232792560
	return 0;
}
