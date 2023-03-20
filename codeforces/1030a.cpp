#include <iostream>

void solve(int n){
  while(n--){
    int x;
    std::cin >> x;
    if(x == 1){
      std::cout << "HARD\n";
      return;
    }
  }
  std::cout << "EASY\n";
}

int main(){
  int n;
  std::cin >> n;
  solve(n);
  return 0;
}
