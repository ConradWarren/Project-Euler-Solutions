#include <iostream>
#include <numeric>

inline bool Is_Smaller_Fraction(long long numerator_1, long long denominator_1, long long numerator_2, long long denominator_2){
	return (numerator_1 * denominator_2 < numerator_2 * denominator_1);
}

int Counting_Fractions_in_a_Range(){

	const int upper_limit = 12000;
	const int target_lower_numerator = 1;
	const int target_lower_denominator = 3;
	const int target_upper_numerator = 1;
	const int target_upper_denominator = 2;
	int result = 0;

	for(int d = 2; d <= upper_limit; d++){
		
		for(int n = 1; n < d; n++){
			
			if(Is_Smaller_Fraction(n, d, target_lower_numerator, target_lower_denominator) || (n == target_lower_numerator && d == target_lower_denominator)){
				continue;
			}

			if(!Is_Smaller_Fraction(n, d, target_upper_numerator, target_upper_denominator)){
				break;
			}


			if(std::gcd(n, d) == 1) result++;
		}
	}

	return result;
}

int main(void){

	std::cout<<Counting_Fractions_in_a_Range()<<std::endl;
	//7295372	
	return 0;
}
