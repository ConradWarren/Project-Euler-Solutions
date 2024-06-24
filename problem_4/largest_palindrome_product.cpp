#include <iostream>

bool is_palindrone(int num){
	
	if(num != 0 && num%10 == 0) return false;
	int current = 0;

	while(current < num){
		current *= 10;
		current += num%10;
		num /= 10;
	}

	return (current == num || current / 10 == num);
}

int largest_palindrone_product(){
	
	const int low = 100;
	const int high = 999;
	int result = 0;

	for(int i = low; i <= high; i++){
		for(int j = i; j <= high; j++){
			if(is_palindrone(i * j)) result = (result > i * j) ? result : i * j;
		}
	}
	
	return result;
}

int main(void){
	
	std::cout<<largest_palindrone_product()<<std::endl;
	//906609	
	return 0;
}
