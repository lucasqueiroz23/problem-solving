#include <iostream>
#include <string>

int main(){

  std::string s, t;

  std::cin >> s >> t;

  int j = t.length() - 1;
  for(int i = 0; i < s.length(); i++){
    if(s[i] != t[j--]){
      std::cout << "NO\n";
      return 0;
    }
  }
  
  std::cout << "YES\n";

  return 0;
}