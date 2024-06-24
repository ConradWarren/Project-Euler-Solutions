#include <iostream>
#include <fstream>
#include <string>

std::string load_input(const std::string& file_path){
	
	std::ifstream file(file_path);
	std::string line;
	std::string input;
	
	while(std::getline(file, line)){
		input += line;
	}
	
	file.close();

	return input;
}

long long largest_product_in_series(){

	std::string series = load_input("input.txt");
	long long result = 0;
	long long current_product = 1;
	const int max_length = 13;
	int back_idx = 0;
	
	for(int i = 0; i < series.size(); i++){
		
		current_product *= (series[i] - '0');
		
		if(current_product == 0){
			back_idx = i+1;
			current_product = 1;
			continue;
		}

		while(i - back_idx + 1 > max_length){
			current_product /= (series[back_idx] - '0');
			back_idx++;
		}
		
		result = (result > current_product) ? result : current_product;
	}

	return result;
}

int main(void){

	std::cout<<largest_product_in_series()<<std::endl;
	//23514624000
	return 0;
}
