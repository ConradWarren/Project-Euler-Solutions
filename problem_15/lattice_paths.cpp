#include <iostream>
#include <vector>

long long Count_Paths(int y, int x, int grid_height, int grid_width, std::vector<std::vector<long long>>& cache){
	
	if(y == grid_height && x == grid_width){
		return 1;
	}
	
	if(y > grid_height || x > grid_width){
		return 0;
	}

	if(cache[y][x] != -1){
		return cache[y][x];
	}

	long long path_down = Count_Paths(y + 1, x, grid_height, grid_width, cache);
	long long path_right = Count_Paths(y, x + 1, grid_height, grid_width, cache);

	return cache[y][x] = path_down + path_right;
}

long long Lattice_Paths(){
	
	const int grid_width = 20;
	const int grid_height = 20;

	std::vector<std::vector<long long>> cache(grid_height + 1, std::vector<long long>(grid_width + 1, -1));

	return Count_Paths(0, 0, grid_height, grid_width, cache);
}


int main(void){
	
	std::cout<<Lattice_Paths()<<std::endl;
	//137846528820
	return 0;
}
