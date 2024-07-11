#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void Load_Input(const std::string& file_path, std::vector<int>& data){
	
	std::ifstream file(file_path);
	std::string current;
	std::string line;
	
	if(!file.is_open()){
		std::cerr<<"Could not open file"<<std::endl;
		return;
	}

	std::getline(file, line);
	
	for(int i = 0; i < line.size(); i++){
		
		if(line[i] == ',' && !current.empty()){
			data.push_back(std::stoi(current));
			current.clear();
		}else if(line[i] != ','){
			current += line[i];
		}
	}

	if(!current.empty()){
		data.push_back(std::stoi(current));
	}
	
	file.close();
}

int Score_Plain_Text(const std::string& plain_text){
	
	int score = 0;

	for(int i = 0; i < plain_text.size(); i++){
		
		if((plain_text[i] >= 'a' && plain_text[i] <= 'z') || (plain_text[i] >= 'A' && plain_text[i] <= 'Z')){
			score += 5;
		}else if(plain_text[i] == ',' || plain_text[i] == '.' || plain_text[i] == '\n' || plain_text[i] == ' '){
			score += 2;
		}
	}
	
	return score;
}

std::string Get_Key(const std::string& cipher_text, int key_size){

	std::string key;
	
	for(int i = 0; i < key_size; i++){
		
		std::string partial_cipher;

		for(int j = i; j < cipher_text.size(); j += key_size){
			partial_cipher += cipher_text[j];
		} 

		std::string decoded_partial_cipher(partial_cipher.size(), 0);
		int best_score = 0;
		int best_key_val = 0;
		for(int j = 0; j < 256; j++){
			
			for(int z = 0; z < decoded_partial_cipher.size(); z++){
				decoded_partial_cipher[z] = static_cast<char>(static_cast<unsigned char>(partial_cipher[z]) ^ static_cast<unsigned char>(j));
			}
			
			int score = Score_Plain_Text(decoded_partial_cipher);
			if(score > best_score){
				best_score = score;
				best_key_val = j;
			}
		}
		
		key += static_cast<char>(best_key_val);
	}

	return key;
}

int XOR_Decryption(){

	std::vector<int> data;
	std::string cipher_text;
	std::string key;
	std::string plain_text;
	int result = 0;

	Load_Input("input.txt", data);

	for(int i = 0; i < data.size(); i++){
		cipher_text += static_cast<char>(data[i]);
	}

	key = Get_Key(cipher_text, 3);
	
	for(int i = 0; i < cipher_text.size(); i++){
		plain_text += static_cast<unsigned char>(cipher_text[i]) ^ static_cast<unsigned char>(key[i%key.size()]);
		result += static_cast<int>(plain_text.back());
	}

	return result;
}

int main(void){
	
	std::cout<<XOR_Decryption()<<std::endl;
	//129448
	return 0;
}
