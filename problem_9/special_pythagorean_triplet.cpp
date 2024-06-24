#include <iostream>
#include <cmath>

int special_pythagorean_triplet(){

	const int triplet_sum = 1000;

	for(int a = 1; a <= triplet_sum/3; a++){
		for(int b = a; b <= triplet_sum/2; b++){
			
			int c_squared = a*a + b*b;
			int c = std::sqrt(c_squared);

			if(c * c == c_squared && a + b + c == triplet_sum){
				return a * b * c;
			}else if(a + b + c > triplet_sum){
				break;
			}
		}
	}
	
	return 0;
}

int main(void){
	
	std::cout<<special_pythagorean_triplet()<<std::endl;
	//31875000
	return 0;
}
