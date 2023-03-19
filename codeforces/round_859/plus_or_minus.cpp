#include <iostream>

void solve(){
  int a = 0, b = 0, c = 0;
  std::cin >> a >> b >> c;
  if((a + b) == c){
    std::cout << "+\n";
    return;
  }
  std::cout << "-\n";
}

int main(){
  int t = 0;
  std::cin >> t;
  while(t--){
    solve();
  }
  return 0;
}