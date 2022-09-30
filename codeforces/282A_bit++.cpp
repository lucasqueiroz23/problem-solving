#include <iostream>

int num;

void solve(){
    std::string str;
    std::cin >> str;
    
    if(str[0] == '-' || str[1] == '-')
        num--;
    if(str[0] == '+' || str[1] == '+')
        num++;
    
}

int main(){
    num = 0;
    int n = 0;
    std::cin >> n;
    
    while(n--){
        solve();
    }
    
    std::cout << num << "\n";
    
    return 0;
}
