#include <iostream>
#include <string>


void solve(std::string word){
	word[0] = toupper(word[0]);

	// string em cpp eh mutavel
	std::cout << word << "\n";

}


int main(){

	std::string word;
	std::cin >> word;

	solve(word);

	return 0;
}
