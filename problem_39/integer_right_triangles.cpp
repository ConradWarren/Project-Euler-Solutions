#include <iostream>
#include <vector>
#include <cmath>

int Integer_Right_Triangles(){
	
	const int upper_limit = 1000;
	int result = 0;
	std::vector<int> solution_count(upper_limit+1, 0);


	for(int a = 1; a <= upper_limit; a++){

		for(int b = a; b <= upper_limit; b++){

			int c = std::sqrt(a * a + b * b);
			
			if(a + b + c > upper_limit){
				break;
			}
			
			if(c * c != a * a + b * b) continue;

			solution_count[a+b+c]++;
			result = (solution_count[result] > solution_count[a+b+c]) ? result : a+b+c;
		}
	}

	
	return result;
}

int main(void){
	
	std::cout<<Integer_Right_Triangles()<<std::endl;
	//840
	return 0;
}
