#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <set>

int Singular_Integer_Right_Triangles(){
	
	const int upper_limit = 1500000;
	const int target = 1;
	std::set<std::vector<int>> cache;
	std::vector<int> ways(upper_limit+1, 0);
	
	int result = 0;

	int m = 2;
	while(2*m*m + 2*m <= upper_limit){
		
		for(int n = 1; 2*m*m + 2 * m * n <= upper_limit && n < m; n++){
			
			if((n%2 == 1 && m%2 == 1) || std::gcd(m, n) > 1) continue;
			
			int l = 2*m*m + 2*m*n;
			int a = m*m - n*n;
			int b = 2 * m * n;
			int c = m*m + n*n;

			for(int k = 1; k*l <= upper_limit; k++){
				if(++ways[k*l] == target) result++;
				else if(ways[k*l] == target+1) result--;
			}
		}	

		m++;
	}

	
	return result;
}

int main(void){
	
	std::cout<<Singular_Integer_Right_Triangles()<<std::endl;
	//161667
	return 0;
}
