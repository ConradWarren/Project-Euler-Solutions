#include <iostream>

int Prime_Factor_Count(int num){

	int count = (num%2 == 0) ? 1 : 0;
	int idx = 3;
	
	while(num%2 == 0){
		num /= 2;
	}
	
	while(idx * idx <= num){

		if(num%idx == 0) count++;

		while(num%idx == 0){
			num /= idx;
		}

		idx += 2;
	}

	if(num != 1) count++;

	return count;
}


int Distinct_Prime_Factors(){
	
	const int target = 4;
	int current_streak = 0;
	int num = 2;

	while(current_streak < target){
		
		if(Prime_Factor_Count(num) == target){
			current_streak++;
		}else{
			current_streak = 0;
		}

		num++;
	}
	
	return num - target;
}

int main(void){

	std::cout<<Distinct_Prime_Factors()<<std::endl;

	return 0;
}
