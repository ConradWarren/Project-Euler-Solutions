#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


void Search_All_Prime_Familys(std::string& num, std::string& current, int target_digit, int idx, std::unordered_map<std::string, int>& prime_family_count_map, std::string& result, int target_count){
	
	if(idx >= num.size()){
		prime_family_count_map[current]++;
		if(prime_family_count_map[current] == target_count){
			result = current;
		}
		return;
	}
	
	if(!result.empty()){
		return;
	}

	current += num[idx];
	Search_All_Prime_Familys(num, current, target_digit, idx+1, prime_family_count_map, result, target_count);
	current.pop_back();

	if(target_digit == -1 || num[idx] - '0' == target_digit){
		current += '.';
		Search_All_Prime_Familys(num, current, num[idx] - '0', idx+1, prime_family_count_map, result, target_count);
		current.pop_back();
	}
}

std::string Count_Prime_Familys(long long num, std::unordered_map<std::string, int>& prime_family_count_map, int target_count){
	
	std::string result;
	std::string str_num = std::to_string(num);
	std::string current;
	
	Search_All_Prime_Familys(str_num, current, -1, 0, prime_family_count_map, result, target_count);

	return result;
}

int Prime_Digit_Replacement(){

	const long long upper_limit = 1000000;
	const int target = 8;
	std::vector<bool> is_prime(upper_limit, true);
	std::unordered_map<std::string, int> prime_family_count_map;
	std::string prime_family;

	is_prime[0] = false;
	is_prime[1] = false;

	for(long long i = 0; i * i < upper_limit; i++){
		
		if(!is_prime[i]) continue;
		for(long long j = i * i; j < upper_limit; j += i){
			is_prime[j] = false;
		}
	} 
	for(long long i = 0; i < upper_limit && prime_family.empty(); i++){
		
		if(!is_prime[i]) continue;
		prime_family = Count_Prime_Familys(i, prime_family_count_map, target);
	}
	
	if(prime_family.empty()) return -1;

	long long num = 0;

	for(int i = (prime_family[0] == '.') ? 1 : 0; i <= 9 && !is_prime[num]; i++){
		
		num = 0;

		for(int j = 0; j < prime_family.size(); j++){
			num *= 10;
			num += (prime_family[j] == '.') ? i : prime_family[j] - '0';
		}
	}

	return num;
}

int main(void){
	
	//121313
	std::cout<<Prime_Digit_Replacement()<<std::endl;

	return 0;
}
