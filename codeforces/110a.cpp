#include <iostream>

bool isLuckyNumber(int number){
  return number == 7 || number == 4 ? true : false;
}

int getNearlyNumberCount(unsigned long long number, int count){
  if(number == 0)
    return count;
  
  if(isLuckyNumber(number%10))
    count++;
  
  return getNearlyNumberCount(number/10, count);
}

int main(){
  unsigned long long n;
  std::cin >> n;
  int count = getNearlyNumberCount(n, 0);

  if(count == 4 || count == 7){
    std::cout << "YES\n";
  }
  else
    std::cout << "NO\n";
  return 0;
}