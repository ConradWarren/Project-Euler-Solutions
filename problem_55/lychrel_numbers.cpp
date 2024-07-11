#include <iostream>
#include <vector>
#include <unordered_map>

bool Is_Palindrome(unsigned long long num){

	long long current = 0;
	if(num%10 == 0) return false;

	while(num > current){
		current *= 10;
		current += num%10;
		num /= 10;
	}
	
	return (num == current || current/10 == num);
}

unsigned long long Get_Reverse_Number(unsigned long long num){
	
	unsigned long long rev = 0;

	while(num){
		rev *= 10;
		rev += num%10;
		num /= 10;
	}
	
	return rev;
}

bool Makes_Palindrome(unsigned long long num, int depth, std::unordered_map<unsigned long long, bool>& cache){
	
	if(cache.find(num) != cache.end()){
		return cache[num];
	}

	if(Is_Palindrome(num)){
		return true;
	}

	if(depth == 50){
		return false;
	}
	unsigned long long new_num = num + Get_Reverse_Number(num);
	
	return cache[num] = Makes_Palindrome(new_num, depth+1, cache);
}

int Lychrel_Numbers(){

	const int upper_limit = 10000;
	int result = 0;
	std::unordered_map<unsigned long long, bool> makes_palindrome_map;
	
	for(int i = 1; i < upper_limit; i++){
	
		if(makes_palindrome_map.find(i) != makes_palindrome_map.end()){
			result += (makes_palindrome_map[i]) ? 0 : 1; 
		}else if(!Makes_Palindrome(i + Get_Reverse_Number(i), 1, makes_palindrome_map)){
			result++;
		}

	}
	
	return result;
}

int main(void){
	
	std::cout<<Lychrel_Numbers()<<std::endl;
	//249
	return 0;
}
