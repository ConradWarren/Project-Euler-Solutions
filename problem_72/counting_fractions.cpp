#include <iostream>

int Eulers_Totient_Function(int num){
	
	if(num <= 1){
		return 0;
	}
	
	int result = num;
	int idx = 3;

	if(num%2 == 0){
		result -= result/2;
	}

	while(num%2 == 0){
		num /= 2;
	}

	while(idx * idx <= num){
		
		if(num%idx == 0){
			result -= result/idx;
		}
		while(num%idx == 0){
			num /= idx;
		}

		idx += 2;
	}

	if(num != 1){
		result -= result/num;
	}

	return result;
}

long long Counting_Fractions(){
	
	const int upper_limit = 1000000;	
	long long result = 0;

	for(int d = 2; d <= upper_limit; d++){		
		result += Eulers_Totient_Function(d);	
	}

	return result;
}

int main(void){
	
	std::cout<<Counting_Fractions()<<std::endl;
	//303963552391
	return 0;
}
