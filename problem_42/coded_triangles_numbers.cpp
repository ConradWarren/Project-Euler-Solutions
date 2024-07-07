#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

void Load_Input(const std::string& input_file_path, std::vector<std::string>& words){
	

	std::ifstream file(input_file_path);
	std::string input;
	std::string current;
	
	if(!file.is_open()){
		std::cout<<"Could not open file\n";
		return;
	}

	std::getline(file, input);
	

	for(int i = 0; i < input.size(); i++){
		
		if(input[i] == ',') continue;
		
		if(input[i] == '"' && !current.empty()){
			words.push_back(current);
			current.clear();
		}else if(input[i] != '"'){
			current += input[i];
		}
	}
	
	if(!current.empty()) words.push_back(current);

	file.close();
}

int Coded_Triangle_Numbers(){
	
	std::vector<std::string> words;
	int result = 0;
	
	Load_Input("input.txt", words);
	
	for(int i = 0; i < words.size(); i++){
		
		int word_score = 0;
		for(int j = 0; j < words[i].size(); j++){
			word_score += (words[i][j] - 'A' + 1);
		}
		word_score *= 2;
		int x = 1 + 4 * word_score;
		int square_x = std::sqrt(x);
		
		if(square_x * square_x != x) continue;
		
		if((square_x - 1)%2 == 0) result++;

	}


	return result;	
}

int main(void){
	
	std::cout<<Coded_Triangle_Numbers()<<std::endl;
	//162 
	return 0;
}
