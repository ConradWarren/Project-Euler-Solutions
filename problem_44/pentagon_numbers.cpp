#include <iostream>
#include <climits>
#include <cmath>

inline long long P(int n){
	return (3 * n * n - n)/2;
}

bool Is_Pentagon_Number(long long num){

	num *= 2;
	long long x = 1 + 4 * 3 * num;
	long long sqrt_x = std::sqrt(x);

	if(sqrt_x * sqrt_x == x && (sqrt_x + 1)%6 == 0){
		return true;
	}

	return false;
}

long long Pentagon_Numbers(){
	
	long long result = INT_MAX;
	long long diff = 0;
	int k = 2;

	while(diff <= result){
		
		long long p_k = P(k);
		long long p_j = P(k-1);
		diff = p_k - p_j;
		
		for(int j = k-1; j > 0; j--){
			p_j = P(j);

			if(Is_Pentagon_Number(p_k + p_j) && Is_Pentagon_Number(p_k - p_j)){
				result = (result < p_k - p_j) ? result : p_k - p_j;
				break;
			}else if(result != INT_MAX && p_k - p_j <= result){
				break;
			}
		}
		k++;
	}
	
	return result;
}
int main(void){

	std::cout<<Pentagon_Numbers()<<std::endl;
	//5482660	
			

	return 0;
}
