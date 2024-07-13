#include <iostream>
#include <vector>
#include <map>

long long Cubic_Permutations(){

	const int upper_limit = 5;
	long long idx = 1;
	long long best_cube = 0;
	int max_frequency = 0;

	std::map<std::vector<int>, std::pair<long long, int>> permutation_map;

	while(max_frequency < upper_limit){
		
		long long cube = idx * idx * idx;
		long long current = cube;
		std::vector<int> counts(10, 0);
		
		while(current){
			counts[current%10]++;
			current /= 10;
		}

		if(permutation_map.find(counts) == permutation_map.end()){
			permutation_map[counts] = {cube, 1};
		}else{
			int frequency = ++permutation_map[counts].second;
			if(frequency > max_frequency || (frequency == max_frequency && best_cube > permutation_map[counts].first)){
				best_cube = permutation_map[counts].first;
				max_frequency = frequency;
			}
		}

		idx++;
	}

	return best_cube;
}

int main(void){
	
	std::cout<<Cubic_Permutations()<<std::endl;
	//127035954683
	return 0;
}
