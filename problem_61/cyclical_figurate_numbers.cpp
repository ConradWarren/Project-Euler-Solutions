#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

void Generate_Triangle_Numbers(std::vector<std::vector<int>>& nums){
	
	int idx = 0;
	int num = 0;
	while(num < 10000){
		
		if(num > 999){
			nums[num/100].push_back(num%100);
		}
		idx++;
		num = (idx * idx + idx)/2;
	}

}

void Generate_Square_Numbers(std::vector<std::vector<int>>& nums){
	
	int idx = 0;
	int num = 0;

	while(num < 10000){
		
		if(num > 999){
			nums[num/100].push_back(num%100);
		}
		idx++;
		num = idx * idx;
	}

}

void Generate_Pentagonal_Numbers(std::vector<std::vector<int>>& nums){
	
	int idx = 0;
	int num = 0;

	while(num < 10000){
		
		if(num > 999){
			nums[num/100].push_back(num%100);
		}
		idx++;
		num = (idx * idx * 3 - idx)/2;
	}
}

void Generate_Hexagonal_Numbers(std::vector<std::vector<int>>& nums){
	
	int idx = 0;
	int num = 0;

	while(num < 10000){
		
		if(num > 999){
			nums[num/100].push_back(num%100);
		}
		idx++;
		num = (idx * idx * 2 - idx);
	}
}

void Generate_Heptagonal_Numbers(std::vector<std::vector<int>>& nums){
	
	int idx = 0;
	int num = 0;

	while(num < 10000){
		
		if(num > 999){
			nums[num/100].push_back(num%100);
		}
		idx++;
		num = (idx * idx * 5 - idx * 3)/2;
	}

}

void Generate_Octagonal_Numbers(std::vector<std::vector<int>>& nums){
	
	int idx = 0;
	int num = 0;
	
	while(num < 10000){
		
		if(num > 999){
			nums[num/100].push_back(num%100);
		}
		idx++;
		num = (idx * idx * 3 - idx * 2);
	}
}

int Get_Sum(const std::vector<std::vector<std::vector<int>>>& graph, int bitmask, int last_num, int starting_num){

	if(bitmask == 0b111111){
		return (last_num == starting_num) ? 0 : static_cast<int>(1e9);
	}
	
	int result = static_cast<int>(1e9);
	for(int i = 0; i < 6; i++){
		
		if(bitmask & (1 << i)) continue;
		
		for(int j = 0; j < graph[i][last_num].size(); j++){
			int current = last_num * 100 + graph[i][last_num][j] + Get_Sum(graph, bitmask | (1 << i), graph[i][last_num][j], starting_num);
			result = (result < current) ? result : current;
		}
	}

	return result;
}

int Cyclical_Figurate_Numbers(){
	
	std::vector<std::vector<std::vector<int>>> graph(6, std::vector<std::vector<int>>(100));
	
	Generate_Triangle_Numbers(graph[0]);
	Generate_Square_Numbers(graph[1]);
	Generate_Pentagonal_Numbers(graph[2]);
	Generate_Hexagonal_Numbers(graph[3]);
	Generate_Heptagonal_Numbers(graph[4]);
	Generate_Octagonal_Numbers(graph[5]);
	
	int result = static_cast<int>(1e9);	
	for(int i = 10; i <= 99; i++){
		int current = Get_Sum(graph, 0, i, i);
		result = (result < current) ? result : current;
	}	

	return result;;
}


int main(void){

	std::cout<<Cyclical_Figurate_Numbers()<<std::endl;
	//28684
	return 0;
}
