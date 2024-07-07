#include <iostream>


bool Is_Palindrome_Base_10(int num){

	int current = 0;

	while(num > current){
		current *= 10;
		current += num%10;
		num /= 10;
	}

	return (num == current || current/10 == num); 
}

bool Is_Palindrome_Base_2(int num){

	int current = 0;

	while(num > current){
		current <<= 1;
		current |= (num & 1);
		num >>= 1;
	}

	return (num == current || (current >> 1) == num);
}

int Double_Base_Palindromes(){
	
	
	const int upper_limit = 1000000;
	int sum = 0;

	for(int i = 1; i < upper_limit; i += 2){
		
		if(Is_Palindrome_Base_10(i) && Is_Palindrome_Base_2(i)) sum += i;

	}

	
	return sum;
}


int main(void){
	
	std::cout<<Double_Base_Palindromes()<<std::endl;

	return 0;
}
