#include <iostream>

int Counting_Sundays(){
	
	const int starting_year = 1901;
	const int end_year = 2000;
	int current_day = 2;
	int result = 0;
	
	for(int i = starting_year; i <= end_year; i++){
		
		for(int j = 0; j < 12; j++){
			
			if(current_day == 0) result++;

			if(j == 1 && ((i%4 == 0 && i % 100 != 0) || (i%400 == 0))){
				current_day += 29;
			}else if(j == 1){
				current_day += 28;
			}else if(j == 3 || j == 5 || j == 8 || j == 10){
				current_day += 30;
			}else{
				current_day += 31;
			}

			current_day %= 7;
		}
	}

	return result;
}


int main(void){
	
	std::cout<<Counting_Sundays()<<std::endl;
	//171


	return 0;
}
