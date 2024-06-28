#include <iostream>
#include <vector>

int Coin_Sums(){
	
	std::vector<int> coins = {1,2,5,10,20,50,100,200};

	const int target_sum = 200;
	std::vector<int> dp(target_sum+1, 0);

	dp[0] = 1;
	
	for(int i = 0; i < coins.size(); i++){
		int coin = coins[i];
		for(int j = 0; j + coin <= target_sum; j++){
			dp[j+coin] += dp[j];
		}
	}

		

	return dp.back();
}


int main(void){
	
	std::cout<<Coin_Sums()<<std::endl;
	//73682
	return 0;
}
