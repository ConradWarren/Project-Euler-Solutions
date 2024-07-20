#include <iostream>
#include <vector>
#include <numeric>



int Eulers_Totient_Function(int num){

	if(num <= 1){
		return 0;
	}

	int idx = 2;
	int result = num;

	while(idx * idx <= num){
		
		if(num%idx == 0){
			result -= result/idx;
		}

		while(num%idx == 0){
			num /= idx;
		}
		idx++;
	}

	if(num != 1){
		result -= result/num;
	}

	return result;
}

int Totient_Maximum(){
	
	const int upper_limit = 1000000;
	int result = 0;
	double max_n_over_totient = -1;
	for(int i = 2; i <= upper_limit; i++){
		
		int count = Eulers_Totient_Function(i);
		double k = static_cast<double>(i)/static_cast<double>(count);

		if(k > max_n_over_totient){
			max_n_over_totient = k;
			result = i;
		}
	}

	return result;
}

int main(void){
	
	std::cout<<Totient_Maximum()<<std::endl;	
	//510510	
	

	return 0;
}
