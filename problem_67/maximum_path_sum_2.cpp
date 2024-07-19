#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void Load_Input(const std::string file_path, std::vector<std::vector<int>>& data){
	
	std::ifstream file(file_path);
	std::string line;
	std::string current;

	if(!file.is_open()){
		std::cerr<<"Error: Could not open file"<<std::endl;
		exit(EXIT_FAILURE);
	}
	
	while(std::getline(file, line)){
		
		data.push_back({});

		for(int i = 0; i < line.size(); i++){
			
			if(line[i] == ' ' && !current.empty()){
				data.back().push_back(std::stoi(current));
				current.clear();
			}else if(line[i] != ' '){
				current += line[i];
			}
		}
		
		if(!current.empty()){
			data.back().push_back(std::stoi(current));
			current.clear();
		}
	}

	file.close();
}

long long Find_Max_Sum(std::vector<std::vector<int>>& nums, int idx, int row, std::vector<std::vector<long long>>& cache){

	if(row >= nums.size()){
		return 0LL;
	}

	if(cache[row][idx] != -1){
		return cache[row][idx];
	}

	long long take_left = nums[row][idx] + Find_Max_Sum(nums, idx, row+1, cache);
	long long take_right = nums[row][idx] + Find_Max_Sum(nums, idx +1, row + 1, cache);

	return cache[row][idx] = (take_left > take_right) ? take_left : take_right;
}

long long Maximum_Path_Sum(){
	
	std::vector<std::vector<int>> data;
	
	Load_Input("input.txt", data);
	
	std::vector<std::vector<long long>> cache(data.size(), std::vector<long long>(data.size(), -1));
	
	return Find_Max_Sum(data, 0, 0, cache);
}

int main(void){
	
	std::cout<<Maximum_Path_Sum()<<std::endl;	
	//7273
	return 0;
}
