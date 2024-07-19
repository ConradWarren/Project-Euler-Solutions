#include <iostream>
#include <string>
#include <vector>

void Search_Ring(int target, int first_external, int first_inner, int target_sum, int last_outer, int bitmask, std::vector<std::vector<int>>& digits, std::vector<std::vector<int>>& result){
	
	if(!result.empty()) return;

	if(bitmask == 0b11111111111){
		
		if(last_outer == first_inner){
			result = digits;
		}
		
		return;
	}

	for(int external = first_external + 1; external <= target && result.empty(); external++){
		
		if(bitmask & (1 << external)) continue;

		int outer = target_sum - last_outer - external;

		if(outer <= 0 || bitmask & (1 << outer) || outer == external) continue;
		
		digits.push_back({external, last_outer, outer});

		Search_Ring(target, first_external, first_inner, target_sum,outer, bitmask | (1 << external) | (1 << outer), digits, result);

		digits.pop_back();
	}
}

std::string Magic_Gon_Ring(){
	
	const int target = 10;
	std::vector<std::vector<int>> digits;
	std::vector<std::vector<int>> result;
	std::string str_result;

	for(int i = target; i > 0 && result.empty(); i--){
		for(int j = target; j > 0 && result.empty(); j--){
			
			if(j == i) continue;

			for(int z = target; z > 0 && result.empty(); z--){

				if(z == j || z == i) continue;
				digits.push_back({i, j, z});
				int bitmask = 1;
				bitmask |= (1 << i);
				bitmask |= (1 << z); 
				Search_Ring(target, i, j, i + j + z, z, 1 | (1 << i) | (1 << z), digits, result);
				digits.pop_back();
			} 
		}
	}

	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[0].size(); j++){
			str_result += std::to_string(result[i][j]);
		}
	}

	return str_result;
}


int main(void){
	
	std::cout<<Magic_Gon_Ring()<<std::endl;
	//6531031914842725
	
	return 0;
}
