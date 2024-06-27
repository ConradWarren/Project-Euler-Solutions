#include <iostream>
#include <vector>


int euler_totient(int num){
	
	int result = num;

	for(int p = 2; p * p <= num; p++){
		
		if(num % p != 0) continue;
	
		while(num % p == 0){
			num /= p;
		}
			
		result -= result / p;
		
	}

	if(num > 1) result -= result / num;

	return result;
}

int get_cycle_length(int num){

	int phi_d = euler_totient(num);
	int k = 1;
	int exp = 10%num;

	while(exp != 1){
		exp = (exp * 10)%num;
		k++;
	}

	return k;
}

int reciprocal_cycles(){
	
	const int upper_limit = 1000;
	int result = 0;
	int max_cycle = 0;	

	for(int i = 2; i < upper_limit; i++){	
	
		if(i%2 == 0 || i % 5 == 0) continue;
		
		int cycle_length = get_cycle_length(i);

		if(cycle_length > max_cycle){
			result = i;
			max_cycle = cycle_length;
		}
	}

	return result;
}

int main(void){
	
	std::cout<<reciprocal_cycles()<<std::endl;
	//983 	
	return 0;
}
