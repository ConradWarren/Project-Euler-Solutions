#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

std::pair<int, int> Find_Arthmetic_Sequence(const std::vector<int>& nums){
	
	for(int i = 0; i < nums.size(); i++){
		
		int idx = i + 1;
		for(int j = i+1; j < nums.size() && idx < nums.size(); j++){
			
			int diff = nums[j] - nums[i];
			
			while(idx < nums.size() && nums[j] + diff > nums[idx]){
				idx++;
			}
			
			if(idx < nums.size() && nums[idx] == nums[j] + diff){
				return {nums[i], diff};
			}
		}
	}
	
	return {-1, -1};
}

std::string Prime_Permutations(){
	
	const int upper_limit = 10000;
	const int min_sequence_length = 3;
	std::vector<bool> is_prime(upper_limit, true);
	std::unordered_map<int, std::vector<int>> bitmask_prime_map;
	int sequence_start = 0;
	int difference = 0;
	std::string result;	

	is_prime[0] = false;
	is_prime[1] = false;

	for(int i = 0; i < upper_limit; i++){
		
		for(int j = i * i; j < upper_limit && is_prime[i]; j += i){
			is_prime[j] = false;
		}	

		if(i < 1000 || !is_prime[i]) continue;

		int num = i;
		int bitmask = 0;
		while(num){
			bitmask |= (1 << (num%10));
			num /= 10;
		}

		bitmask_prime_map[bitmask].push_back(i);
	}
	
	for(auto x : bitmask_prime_map){
		
		if(x.second.size() < min_sequence_length) continue;
		
		if(x.second[0] == 1487){
			continue;	
		}

		std::pair<int, int> sequence = Find_Arthmetic_Sequence(x.second);

		if(sequence.first != -1){
			sequence_start = sequence.first;
			difference = sequence.second;
		}
	}

	for(int i = 0; i < min_sequence_length; i++){
		result += std::to_string(sequence_start);
		sequence_start += difference;
	}	
	
	return result;
}

int main(void){
	
	std::cout<<Prime_Permutations()<<std::endl;
	//296962999629 
	return 0;
}
