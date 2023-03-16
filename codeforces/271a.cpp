#include <iostream>
#include <string>

bool allCharsAreDistinct(int y){
  std::string year = std::to_string(y);
  for(int i = 0; i < year.size() - 1; i++){
    for(int j = i + 1; j < year.size(); j++){
      if(year[i] == year[j])
        return false;
    }
  }
  return true;
}

void solve(int year){
  year++;
  while(!allCharsAreDistinct(year))
    year++;
  
  std::cout << year << "\n";
}

int main(){
  int year;
  std::cin >> year;

  solve(year);
  return 0;
}