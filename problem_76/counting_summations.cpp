#include <iostream>
#include <vector>

int Counting_Summations(){
	
	const int target = 100;
	std::vector<int> ways(target+1, 0);
	
	ways[0] = 1;

	for(int i = 1; i < target; i++){
		for(int j = 0; j + i <= target; j++){
			ways[j+i] += ways[j];
		}
	}

	return ways[target];
}

int main(void){
	
	std::cout<<Counting_Summations()<<std::endl;
	//190569291
	return 0;
}
