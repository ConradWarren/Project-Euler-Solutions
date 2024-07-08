#include <iostream>

int Count_Valid_R_Values(long long lower_bound, int n){
	
	int low = 0;
	int high = n;
	long long current_product = 1;
	
	while(current_product <= lower_bound && low < high){
		current_product *= high;
		low++;
		high--;
		current_product /= low;
	}

	return (current_product <= lower_bound) ? 0 : (high - low + 1);
}


int Combinatoric_Selections(){

	int n_upper_bound = 100;
	int lower_bound = 1000000;
	int result = 0;

	for(int i = 1; i <= n_upper_bound; i++){
		result += Count_Valid_R_Values(lower_bound, i);	
	}
	
	return result;
}

int main(void){
	
	std::cout<<Combinatoric_Selections()<<std::endl;
	//4075
	return 0;
}
