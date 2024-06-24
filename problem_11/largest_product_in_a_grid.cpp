#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void Load_Input(const std::string& file_path, std::vector<std::vector<int>>& grid){

	std::ifstream file(file_path);
	std::string line;
	
	while(std::getline(file, line)){

		std::string current;
		grid.push_back({});

		for(int i = 0; i < line.size(); i++){
			if(line[i] == ' ' && !current.empty()){
				grid.back().push_back(std::stoi(current));
				current.clear();
			}else if(line[i] != ' '){
				current += line[i];
			}
		}

		if(!current.empty()){
			grid.back().push_back(std::stoi(current));
		}
	}
	

	file.close();
}

int Largest_Product_In_a_Sequence(std::vector<std::vector<int>>& grid, int start_y, int start_x, const std::pair<int, int>& direction){
	
	const int max_length = 4;
	int result = 0;
	int current_product = 1;
	int y = start_y;
	int x = start_x;
	int back_y = start_y;
	int back_x = start_x;
	
	while(y >= 0 && y < grid.size() && x >= 0 && x < grid[y].size()){

		current_product *= grid[y][x];

		if(current_product == 0){
			current_product = 1;
			y += direction.first;
			x += direction.second;
			back_y = y;
			back_x = x;
			continue;
		}
		
		while(std::abs(y - back_y + 1) > max_length || std::abs(x - back_x + 1) > max_length){
			current_product /= grid[back_y][back_x];
			back_y += direction.first;
			back_x += direction.second;
		}

		result = (result > current_product) ? result : current_product;
		y += direction.first;
		x += direction.second;
	}

	return result;
}

int Largest_Product_In_a_Grid(){
	
	std::vector<std::vector<int>> grid;
	Load_Input("input.txt", grid);
	

	int result = 0;
	
	for(int i = 0; i < grid.size(); i++){
		int horizontal_product = Largest_Product_In_a_Sequence(grid, i, 0, {0, 1});
		int negative_diagonal_product = Largest_Product_In_a_Sequence(grid, i, 0, {1, 1});
		int positive_diagonal_product = Largest_Product_In_a_Sequence(grid, i, 0, {-1, 1});
		result = (result > horizontal_product) ? result : horizontal_product;
		result = (result > negative_diagonal_product) ? result : negative_diagonal_product;
		result = (result > positive_diagonal_product) ? result : positive_diagonal_product;
	}
	
	for(int i = 0; i < grid[0].size(); i++){
		int vertical_product = Largest_Product_In_a_Sequence(grid, 0, i, {1, 0});
		int negative_diagonal_product = Largest_Product_In_a_Sequence(grid, 0, i, {1, 1});
		int positive_diagonal_product = Largest_Product_In_a_Sequence(grid, grid.size() - 1, i, {-1, 1});
		result = (result > vertical_product) ? result : vertical_product;
		result = (result > negative_diagonal_product) ? result : negative_diagonal_product;
		result = (result > positive_diagonal_product) ? result : positive_diagonal_product;
	}
	
	return result;
}




int main(void){
	
	std::cout<<Largest_Product_In_a_Grid()<<std::endl;
	//70600674

	return 0;
}
