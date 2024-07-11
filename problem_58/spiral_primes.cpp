#include <iostream>
#include <vector>

bool Is_Prime(long long num){

	if(num == 2 || num == 3) return true;

	if(num == 1 || num%2 == 0) return false;

	if((num + 1)%6 != 0 && (num - 1)% 6 != 0) return false;

	long long idx = 3;
	while(idx * idx <= num){
		if(num%idx == 0) return false;
		idx += 2;
	}
	
	return true;
}

int Spiral_Primes(){
	
	const double target_ratio = 0.1;
	int prime_count = 0;
	int corner_count = 1;
	int result = 0;		
	int edge_length = 1;
	int max_value = 1;

	do{
		edge_length += 2;
		int first_corner = max_value + edge_length - 1;
		
		for(int i = 0; i < 4; i++){
			if(Is_Prime(first_corner + i * (edge_length -1))) prime_count++;
		}
		
		corner_count += 4;
		max_value += edge_length * 4 - 4; 

	}while(static_cast<double>(prime_count)/corner_count >= target_ratio);

	return edge_length;
}

int main(void){
	
	std::cout<<Spiral_Primes()<<std::endl;
	//26241
	return 0;
}
