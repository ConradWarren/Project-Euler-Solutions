#include <iostream>

int Spiral_Diagonals(){
	
	const int upper_limit = 1001;
	int sum = 1;
	int side_length = 3;

	while(side_length <= 1001){
		int start_point = (side_length - 2) * (side_length - 2) + 1;
		int first_corner = start_point + side_length-2;
		sum += 4 * first_corner + 6 * (side_length - 1);
		side_length += 2;
	}

	return sum;
}


int main(void){
	
	std::cout<<Spiral_Diagonals()<<std::endl;
	//669171001
	return 0;
}
