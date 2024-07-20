#include <iostream>
#include <numeric>

inline bool Is_Fraction_Smaller(long long numerator_1, long long denominator_1, long long numerator_2, long long denominator_2){
	return (numerator_1 * denominator_2 < numerator_2 * denominator_1);
}

int Ordered_Fraction(){
	
	const int upper_limit = 1000000;
	const int target_numerator = 3;
	const int target_denominator = 7;
	int result_numerator = 0;
	int result_denomirator = 1;

	for(int d = upper_limit; d >= 2; d--){
		
		int high = d-1;
		int low = 1;

		while(low < high){
			
			int mid = (low + high)/2;
			if(Is_Fraction_Smaller(mid, d, target_numerator, target_denominator)){
				low = mid + 1;
			}else{
				high = mid;
			}
		}
		
		if(Is_Fraction_Smaller(result_numerator,result_denomirator, low-1, d)){
			result_numerator = low-1;
			result_denomirator = d;

			int gcd = std::gcd(result_numerator, result_denomirator);
			result_numerator /= gcd;
			result_denomirator /= gcd;
		} 
	}
	
	return result_numerator;
}

int main(void){
	
	std::cout<<Ordered_Fraction()<<std::endl;
	//428570
	return 0;
}
