#include <iostream>
#include <vector>

int Champernownes_Constant(){

	const std::vector<int> target_idx = {1, 10, 100, 1000, 10000, 100000, 1000000};
	int idx = 0;
	int num_idx = 0;
	int result = 1;
	int num = 1;

	while(idx < target_idx.size()){
		
		int current = num;
		int reversed_num = 1;
		while(current){
			reversed_num *= 10;
			reversed_num += current%10;
			current /= 10;
		}	
		while(reversed_num > 1){
			
			num_idx++;
			if(num_idx == target_idx[idx]){
				result *= reversed_num%10; 
				idx++;
			}
			reversed_num /= 10;
		}
		num++;
	}
	return result;
}


int main(void){
	
	std::cout<<Champernownes_Constant()<<std::endl;
	//210
	return 0;
}
