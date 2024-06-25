#include <iostream>
#include <string>
#include <vector>


int Letter_Count(int num){
	
	static const std::vector<std::string> first_digit = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	static const std::vector<std::string> second_digit = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	static const std::vector<std::string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	static const std::string third_digit = "hundred";
	static const std::string fourth_digit = "thousand";

	int sum = 0;

	if(num/1000 > 0){
		sum += first_digit[num/1000 - 1].size() + fourth_digit.size();
	}

	if((num/100)%10 > 0){
		sum += first_digit[(num/100)%10 - 1].size() + third_digit.size();
	}
	
	if(num >= 100 && num%100 > 0){
		sum += 3;
	}
	
	if((num/10)%10 == 1){
		sum += teens[num%10].size();
		return sum;
	}

	if((num/10)%10 > 0){
		sum += second_digit[(num/10)%10 - 1].size();
	}

	if(num%10 > 0){
		sum += first_digit[num%10 - 1].size();
	}

	return sum;
}

int Number_Letter_Counts(){
	
	const int upper_limit = 1000;
	int result = 0;

	for(int i = 1; i <= upper_limit; i++){
		result += Letter_Count(i);	
	}
	
	return result;
}


int main(void){

	std::cout<<Number_Letter_Counts()<<std::endl;
	//21124
	return 0;
}
