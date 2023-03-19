#include <iostream>
#include <string>
#include <cstdlib>

bool replace(std::string s, int n, int initialVal = 0){
  for(int i = 0; i < n; i++){
    char repChar;
    if(initialVal == 0){
      if(i%2==0){
        repChar = '0';
      } else {
        repChar = '1';
      }
    }
    if(initialVal == 1){
      if(i%2==0){
        repChar = '1';
      } else {
        repChar = '0';
      }
    }


    char findChar = s[i];
    for(int j = i; j < n; j++){
      if(s[j] == findChar){
        s[j] = repChar;
        if(j - 1 > -1){
          if(s[j-1] == repChar){
            return false;
          }
        }
        if(j + 1 < n){
          if(s[j+1] == repChar){
            return false;
          }
        }
      }
    }
  }
  return true;
}

void solve(){
  int n = 0;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  if(replace(s,n) || replace(s,n,1)){
    std::cout << "YES\n";
    return;
  }
  std::cout << "NO\n";
}

int main(){
  int t = 0;
  std::cin >> t;
  while(t--){
    solve();
  }
  return 0;
}