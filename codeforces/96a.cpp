#include <iostream>
#include <string>

bool situationIsDangerous(std::string field){
  if(field.size() < 7)
    return false;
  int count = 1;
  for(auto i = 1; i < field.size(); i++){
    char player = field[i];
    if(player != field[i-1]){
      count = 0;
    }
    count++;
    if(count == 7){
      return true;
    }
  }
  return false;
}

int main(){
  std::string field;
  std::cin >> field;
  
  std::string situation = situationIsDangerous(field) ? "YES\n" : "NO\n";
  std::cout << situation;
  return 0;
}