#include <iostream>
int n, k;

int main(){
  std::cin >> n >> k;
  while(k--){
    if((n%10)%10 == 0){
      n/=10;
    }
    else
      n--;
  }
  std::cout << n << "\n";
  return 0;
}