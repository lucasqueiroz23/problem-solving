#include <iostream>
#include <string>

int alphabet[26];

void init_alphabet() {
  for(int i = 0; i < 26; i++){
    alphabet[i] = 0;
  }
}

bool isFemale(std::string username){

  init_alphabet();
  int numDistinctCharacters = 0;

  for(char letter: username){
    int letterPositionInAlphabet = (int) letter % 26;

    if(alphabet[letterPositionInAlphabet] == 0){
      alphabet[letterPositionInAlphabet] = 1;
      numDistinctCharacters++;
    }
  }
  bool isFemale =  numDistinctCharacters % 2 == 0;
  return isFemale ? true : false;
}

int main(){

  std::string username;
  std::cin >> username;

  if(isFemale(username))
    std::cout << "CHAT WITH HER!\n";
  else
    std::cout << "IGNORE HIM!\n";

  return 0;
}