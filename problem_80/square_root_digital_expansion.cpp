#include <iostream>
#include <cmath>
#include <vector>

inline int Get_Digit_Count(int num){
	int result = 0;
	while(num){
		result++;
		num /= 10;
	}
	return result;
}

bool Square_Large_Number(const std::vector<int>& num, int floating_point_position, int target){
	
	std::vector<int> result(num.size()*2 + 1, 0);
	int n = num.size();

	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j >= 0; j--){
			int product = num[i] * num[j];
			result[n-1-j+n-1-i] += product;
			result[n-1-j+n-1-i+1] += result[n-1-j+n-1-i]/10;
			result[n-1-j+n-1-i] %= 10;
		}
	}
	
	floating_point_position *= 2;
	int rounded_num = 0;
	for(int i = static_cast<int>(result.size()) - 1; i >= floating_point_position; i--){
		rounded_num *= 10;
		rounded_num += result[i];
	}

	return (rounded_num < target);
}

long long Square_Root_Digital_Expansion(){
	
	const int upper_limit = 100;
	int num = 0;
	long long result = 0;
	
	while(num <= upper_limit){
		
		int square = std::sqrt(num);
		
		if(square * square == num){
			num++;
			continue;
		}

		int digit_count = Get_Digit_Count(square);
		std::vector<int> large_num(digit_count);
		
		for(int i = digit_count - 1; i >= 0; i--){
			large_num[i] = square%10;
			result += square%10;
			square /= 10;
		}
		
		for(int i = digit_count+1; i <= 100; i++){
			
			large_num.push_back(0);
			int low = 1;
			int high = 10;
			while(low < high){
				
				int mid = (low + high)/2;
				large_num.back() = mid;
				
				if(Square_Large_Number(large_num, i - digit_count, num)){
					low = mid+1;
				}else{
					high = mid;
				}
			}
			
			large_num.back() = low-1;
			result += low-1;
		}
		num++;
	}

	return result;
}

int main(void){
	
	std::cout<<Square_Root_Digital_Expansion()<<std::endl;
	//40886 	

	return 0;
}
