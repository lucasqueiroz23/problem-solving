#include <iostream>
#include <string>
#include <vector>


int vowels[127];

void insertVowelHash(){
	int asciiVowels[6] = {97,101,105,111,117,121};
	for(int i = 0; i < 127; i++)
		vowels[i] = 0;
	for(int vowel: asciiVowels){
		vowels[vowel] = 1;
	}

}

void solve(std::string str){

	insertVowelHash();

	std::vector<char> finalStr;

	for(int i = 0; i < str.length(); i++){
			if( vowels[(int) tolower(str[i])] == 1)
				continue;
			finalStr.push_back('.');
			finalStr.push_back(tolower(str[i]));
	}
	for(int i = 0; i < finalStr.size(); i++)
		std::cout << finalStr[i];

	std::cout <<"\n";
}

int main(){


	std::string str;
	std::cin >> str;

	solve(str);

	return 0;
}
