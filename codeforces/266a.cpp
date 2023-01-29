#include <iostream>
#include <string>

int n;
std::string s;

unsigned getNumOfEqualNeighbors(){
  unsigned count = 0;

  for(unsigned i = 0; i < n - 1; i++){
    if(s[i] == s[i+1])
      count++;
  }

  return count;
}

int main(){

  std::cin >> n >> s;
  std::cout << getNumOfEqualNeighbors() << "\n";

  return 0;
}