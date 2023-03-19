#include <iostream>
#include <string>

std::string solve(int n){
  int evenSum = 0, oddSum = 0;
  while(n--){
    int x = 0;
    std::cin >> x;
    if(x%2 == 0){
      evenSum += x;
    } else {
      oddSum += x;
    }
  }

  return (evenSum > oddSum) ? "YES\n" : "NO\n";
}

int main(){
  int t = 0;
  std::cin >> t;
  while(t--){
    int n = 0;
    std::cin >> n;

    std::cout << solve(n);
  }
  return 0;
}