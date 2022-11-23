#include <iostream>
#include <string>

void solve(char char1, char char2){
	int posicoesAscii[2] = {(int) char1, (int) char2};
	if(posicoesAscii[0] > posicoesAscii[1])
		std::cout << "1";
	else
		std::cout << "-1";

	std::cout <<"\n";

}

int main(){
	std::string str1, str2;
	std::cin >> str1 >> str2;

	for(int i = 0; i< str1.length(); i++){
		if(tolower(str1[i]) != tolower(str2[i])){
			solve(tolower(str1[i]), tolower(str2[i]));
			return 0;
		}
	}
	std::cout << "0\n";

	return 0;
}
