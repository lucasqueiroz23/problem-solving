#include <iostream>
#include <string>

int main(){
  std::string hello = "hello";
  std::string s;

  std::cin >> s;

  int count = 0;

  for(int i = 0; i < s.length(); i++){
    if(s[i] == hello[count])
      count++;
    if(count == 5)
      break;
  }

  std::cout << (count == 5 ? "YES\n" : "NO\n");

  return 0;
}