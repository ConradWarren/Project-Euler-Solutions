#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

void Load_Data(const std::string& file_path, std::vector<std::vector<int>>& nums){
	
	std::ifstream file(file_path);
	std::string line;
	
	if(!file.is_open()){
		std::cerr<<"Error: Could not open file"<<std::endl;
	}

	while(std::getline(file, line)){

		std::vector<int> current(line.size());
		for(int i = 0; i < line.size(); i++){
			current[i] = line[i] - '0';
		}

		nums.push_back(current);
	}
	
	file.close();
}

std::string Passcode_Derivation(){
	
	std::vector<std::vector<int>> conditions;
	std::vector<std::vector<int>> graph(10);
	std::vector<int> n_degree(10, 0);
	std::queue<int> node_queue;
	std::string result;

	Load_Data("input.txt", conditions);	
	

	for(int i = 0; i < conditions.size(); i++){
		n_degree[conditions[i][2]] += 2;
		n_degree[conditions[i][1]]++;

		graph[conditions[i][0]].push_back(conditions[i][1]);
		graph[conditions[i][0]].push_back(conditions[i][2]);
		graph[conditions[i][1]].push_back(conditions[i][2]);
	}

	for(int i = 0; i < n_degree.size(); i++){
		if(n_degree[i] == 0 && !graph[i].empty()) node_queue.push(i);
	}


	while(!node_queue.empty()){
		
		int node = node_queue.front();
		node_queue.pop();
		result += ('0' + node);
		
		for(int i = 0; i < graph[node].size(); i++){
			if(--n_degree[graph[node][i]] == 0){
				node_queue.push(graph[node][i]);
			}
		}
	}
	return result;
}

int main(void){
	
	std::cout<<Passcode_Derivation()<<std::endl;
	//73162890
	
	return 0;
}
