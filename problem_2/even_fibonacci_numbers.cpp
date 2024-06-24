#include <iostream>

long long Sum_of_Even_Fibonacci_Numbers(){
	
	const int limit = (int)4e6 + 1;
	long long sum = 0;
	int prev_fib = 1;
	int last_fib = 1;

	while(prev_fib + last_fib < limit){
		
		int temp = prev_fib;
		prev_fib += last_fib;
		last_fib = temp;
		if(prev_fib % 2 == 0) sum += prev_fib;
	}
	
	return sum;
}


int main(void){

	std::cout<<Sum_of_Even_Fibonacci_Numbers()<<std::endl;
	
	//4613732
	return 0;
}
