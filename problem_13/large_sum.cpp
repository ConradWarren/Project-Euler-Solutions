#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Load_Input(const std::string& file_path, std::vector<std::vector<long long>>& nums){
	
	std::ifstream file(file_path);
	std::string line;

	while(std::getline(file, line)){
		nums.push_back(std::vector<long long>(line.size()/10));

		for(int i = 0; i < line.size(); i += 10){
			nums.back()[i/10] = std::stoll(line.substr(i, 10));
		}
	}

}

long long Large_Sum(){
	
	std::vector<std::vector<long long>> nums;
	long long sum = 0;
	long long carry = 0;	
	
	Load_Input("input.txt", nums);
	
	
	for(int i = (int)nums[0].size() - 1; i >= 0; i--){
		
		sum = carry;
		carry = 0;
		for(int j = 0; j < nums.size(); j++){
			sum += nums[j][i];
			while(sum > (long long)1e10){
				carry++;
				sum -= (long long)1e10;
			}
		}
	}

	sum += carry * (long long)1e10;
		
	while(sum >= (long long)1e10){
		sum /= 10;
	}

	return sum;
}


int main(void){

	std::cout<<Large_Sum()<<std::endl;

	return 0;
}
