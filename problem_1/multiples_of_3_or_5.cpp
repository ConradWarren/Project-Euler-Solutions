#include <iostream>

int sum_of_multiples(int factor, int limit){
		
	int multiple_count = (limit-1) / factor;

	return factor * ((multiple_count * (multiple_count + 1))/2);
}

int multiples_of_3_or_5(){

	return sum_of_multiples(3, 1000) + sum_of_multiples(5, 1000) - sum_of_multiples(15, 1000);
}

int main(void){

	std::cout<<multiples_of_3_or_5()<<std::endl;

	return 0;
}
