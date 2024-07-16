#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

inline bool Is_Square(long long num){
	
	long long sqrt = std::sqrt(num);
	
	return (sqrt * sqrt == num);
}

std::pair<long long, long long> Get_Convergant_Fraction(std::vector<long long>& values){
	
	if(values.size() == 1) return {values[0], 1};
	
	long long denominator = values.back();
	long long numerator = 1;

	for(int i = static_cast<int>(values.size()) - 2; i > 0; i--){
		
		numerator += values[i] * denominator;
		long long gcd = std::gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;

		std::swap(numerator, denominator);
	}

	numerator += denominator * values[0];

	long long gcd = std::gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	std::cout<<numerator<<" "<<denominator<<std::endl;

	return {numerator, denominator};
}

long long Diophantine_Equation(){
	
	const int upper_limit = 2;

	for(long long d = 2; d <= upper_limit; d++){
				
		long long a = static_cast<long long>(std::sqrt(d));
		long long numerator = -a;
		long long factor = 1;
		long long denomirator = 1;
		
		if(a * a == d || d == 421) continue;
		
		std::vector<long long> a_values = {a};
		if(a * a - d == 1){
			std::cout<<d<<" : "<<a<<std::endl;
		} 
		std::cout<<a<<std::endl;
		while(true){
			
			long long rationalized_denomirator = factor * factor * d + numerator * numerator * -1;
			factor *= denomirator; 
			numerator = denomirator * -numerator;
			denomirator = rationalized_denomirator;
			
			long long gcd = std::gcd(factor, std::gcd(numerator, denomirator));

			factor /= gcd;
			numerator /= gcd;
			denomirator /= gcd;

			a = static_cast<long long>(static_cast<double>(std::sqrt(d) * factor + numerator)/static_cast<double>(denomirator));
			a_values.push_back(a);
			std::cout<<a<<std::endl;
			numerator -= a * denomirator;
			
			std::pair<long long, long long> fraction = Get_Convergant_Fraction(a_values);
			
			if(fraction.first * fraction.first - d * fraction.second * fraction.second == 1){
				std::cout<<d<<" : "<<fraction.first<<std::endl;
				break;
			}
		}
	}
			
		
	return 0;
}


int main(void){
	
	std::cout<<Diophantine_Equation()<<std::endl;

	return 0;
}

