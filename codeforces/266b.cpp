#include <iostream>
#include <string>
int main(){
  int n = 0;
  int t = 0;

  std::string s;

  std::cin >> n >> t >> s;

  while(t--){
    for(int i = 0; i < n - 1; i++){
      if(s[i] == 'B' && s[i+1] == 'G'){
        char temp = s[i];
        s[i] = s[i+1];
        s[i+1] = temp;
        i++;
      }
    }
  }
  std::cout << s << "\n";

  return 0;
}