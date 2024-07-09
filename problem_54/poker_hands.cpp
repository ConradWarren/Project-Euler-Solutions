#include <iostream>
#include <vector>
#include <fstream>
#include <string>

enum suits{clubs, diamonds, hearts, spades};

void Load_Input(const std::string& file_path, std::vector<std::vector<std::pair<int, int>>>& hands){
	
	std::ifstream file(file_path);
	std::string line;

	if(!file.is_open()){
		std::cout<<"Could not open file\n";
		return;
	}
	

	while(std::getline(file, line)){
		
		hands.push_back({});

		for(int i = 0; i < line.size(); i += 3){
			
			int suit = 0;
			int card = 0;
		 	if(line[i] - '0' >= 1 && line[i] - '0' <= 9){
				card = line[i] - '0';
			}
			else if(line[i] == 'T'){
				card = 10;
			}
			else if(line[i] == 'J'){
				card = 11;
			}
			else if(line[i] == 'Q'){
				card = 12;
			}
			else if(line[i] == 'K'){
				card = 13;
			}
			else if(line[i] == 'A'){
				card = 14;
			}

			if(line[i+1] == 'C'){
				suit = suits::clubs;
			}else if(line[i+1] == 'D'){
				suit = suits::diamonds;
			}else if(line[i+1] == 'H'){
				suit = suits::hearts;
			}else if(line[i+1] == 'S'){
				suit = suits::spades;
			}
			
			if(hands.back().size() == 5){
				hands.push_back({});
			}
			hands.back().push_back({card, suit});
		}		
	}

	file.close();
}

bool Compare_Hands(std::vector<std::pair<int, int>>& hand_1, std::vector<std::pair<int, int>>& hand_2){

	std::vector<int> suit_counts_1(4, 0);
	std::vector<int> suit_counts_2(4, 0);
	std::vector<int> card_counts_1(15, 0);
	std::vector<int> card_counts_2(15, 0);

	bool flush_flag_1 = false;
	int straight_flag_1 = -1;
	int four_kind_flag_1 = -1;
	int three_kind_flag_1 = -1;
	int two_pair_flag_1 = -1;
	int pair_flag_1 = -1;
	int high_card_1 = -1;

	bool flush_flag_2 = false;
	int straight_flag_2 = -1;
	int four_kind_flag_2 = -1;
	int three_kind_flag_2 = -1;
	int two_pair_flag_2 = -1;
	int pair_flag_2 = -1;
	int high_card_2 = -1;
	
	for(int i = 0; i < hand_1.size(); i++){
		
		if(++suit_counts_1[hand_1[i].second] == 5) flush_flag_1 = true;
		if(++suit_counts_2[hand_2[i].second] == 5) flush_flag_2 = true;
		
		card_counts_1[hand_1[i].first]++;
		card_counts_2[hand_2[i].first]++;
	}

	int consecutive_count_1 = 0;
	int consecutive_count_2 = 0;

	for(int i = 0; i < card_counts_1.size(); i++){

		if(card_counts_1[i]) consecutive_count_1++;
		else consecutive_count_1 = 0;
		if(consecutive_count_1 == 5) straight_flag_1 = i;
		
		if(card_counts_2[i]) consecutive_count_2++;
		else consecutive_count_2 = 0;
		if(consecutive_count_2 == 5) straight_flag_2 = i;

		if(card_counts_1[i] == 2 && pair_flag_1 != -1){
			two_pair_flag_1 = i;
		}
		else if(card_counts_1[i] == 2){
			pair_flag_1 = i;
		}
		else if(card_counts_1[i] == 3){
			three_kind_flag_1 = i;
		}else if(card_counts_1[i] == 4){
			four_kind_flag_1 = i;
		}
		if(card_counts_1[i]){
			high_card_1 = i;
		}

		if(card_counts_2[i] == 2 && pair_flag_2 != -1){
			two_pair_flag_2 = i;
		}
		else if(card_counts_2[i] == 2){
			pair_flag_2 = i;
		}
		else if(card_counts_2[i] == 3){
			three_kind_flag_2 = i;
		}else if(card_counts_2[i] == 4){
			four_kind_flag_2 = i;
		}
		if(card_counts_2[i]){
			high_card_2 = i;
		}
	}
	
	if((flush_flag_1 && straight_flag_1 != -1) || (flush_flag_2 && straight_flag_2 != -1)){
		if(!(flush_flag_1 && flush_flag_2)) return flush_flag_1;
		if(straight_flag_1 != straight_flag_2) return straight_flag_1 > straight_flag_2;
	}

	if(four_kind_flag_1 != -1 || four_kind_flag_2 != -1){
		return four_kind_flag_1 > four_kind_flag_2;
	}

	if((three_kind_flag_1 != -1 && pair_flag_1 != -1) || (three_kind_flag_2 != -1 && pair_flag_2 != -1)){
		if(!(three_kind_flag_1 != -1 && pair_flag_1 != -1 && three_kind_flag_2 != -1 && pair_flag_2 != -1)) return (three_kind_flag_1 != -1 && pair_flag_1 != -1);
		return (three_kind_flag_1 > three_kind_flag_2);
	}

	if(flush_flag_1 ^ flush_flag_2){
		return flush_flag_1;
	}

	if(straight_flag_1 != straight_flag_2){
		return straight_flag_1 > straight_flag_2;
	}

	if(three_kind_flag_1 != -1 || three_kind_flag_2 != -1){
		return three_kind_flag_1 > three_kind_flag_2;
	}

	if(two_pair_flag_1 != two_pair_flag_2){
		return two_pair_flag_1 > two_pair_flag_2;
	}

	if(pair_flag_1 != pair_flag_2) return pair_flag_1 > pair_flag_2;

	return high_card_1 > high_card_2;
}

int Poker_Hands(){

	std::vector<std::vector<std::pair<int, int>>> hands;
	int result = 0;

	Load_Input("input.txt", hands);

	for(int i = 0; i < hands.size(); i += 2){
		
		if(Compare_Hands(hands[i], hands[i+1])) result++;
	}
	

	return result;
}

int main (void){

	std::cout<<Poker_Hands()<<std::endl;	
	//376
	return 0;
}
