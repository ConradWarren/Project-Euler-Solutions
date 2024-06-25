#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void Load_Input(const std::string& file_path, std::vector<std::string>& names){
	
	std::ifstream file(file_path);
	std::string name;

	while(std::getline(file, name, ',')){
		names.push_back(name.substr(1, name.size() - 2));
	}
	names.back().pop_back();
}

unsigned long long Names_Scores(){

	std::vector<std::string> names;
	unsigned long long result = 0;
	
	Load_Input("input.txt", names);
	std::sort(names.begin(), names.end());

	
	for(int i = 0; i < names.size(); i++){
		
		long long score = 0;
		for(int j = 0; j < names[i].size(); j++){
			score += names[i][j] - 'A' + 1;
		}
		result += score * (i+1);
	}

	return result;
}

int main(void){
	
	std::cout<<Names_Scores()<<std::endl;
	//871198282
	return 0;
}
