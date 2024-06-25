#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void Load_Input(const std::string& file_path, std::vector<std::vector<int>>& nums){
	
	std::ifstream file(file_path);
	std::string line;

	while(std::getline(file, line)){

		std::string current;
		nums.push_back({});

		for(int i = 0; i < line.size(); i++){
			
			if(line[i] == ' ' && !current.empty()){
				nums.back().push_back(std::stoi(current));
				current.clear();
			}else if(line[i] != ' '){
				current += line[i];
			}
		}

		if(!current.empty()){
			nums.back().push_back(std::stoi(current));
		}
	}
	
	file.close();
}

int Solve_Max_Path(int idx, int row,const std::vector<std::vector<int>>& nums, std::vector<std::vector<int>>& cache){
	
	if(row >= nums.size() || idx >= nums[row].size()){
		return 0;
	}

	if(cache[row][idx] != -1){
		return cache[row][idx];
	}
	
	int down = nums[row][idx] + Solve_Max_Path(idx, row+1, nums, cache);
	int down_right = nums[row][idx] + Solve_Max_Path(idx+1, row+1, nums, cache);

	return cache[row][idx] = (down > down_right) ? down : down_right;
}

int Maximum_Path_Sum(){
	
	std::vector<std::vector<int>> nums;
	std::vector<std::vector<int>> cache;

	Load_Input("input.txt", nums);
	
	cache.resize(nums.size(), std::vector<int>(nums.size(), -1));

	return Solve_Max_Path(0, 0, nums, cache);
}

int main(void){
	
	std::cout<<Maximum_Path_Sum()<<std::endl;
	//1074
	
	return 0;
}
