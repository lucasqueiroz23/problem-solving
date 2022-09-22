#include <iostream>
#include <string>


void solve(int n, int m, int *bills, std::string *res){
    int diff = m-n;
    int i = 0, j = 1;
    while(i<5){
        while(j<6){
            if(bills[i] + bills[j] == diff){
                std::cout << res[0];
                return;
            }
            j++;
        }
        
        i++;
        j = i+1;
    }
    
    std::cout << res[1];
}
 
int main() {
    
    int bills[6] = {2,5,10,20,50,100};
    std::string res[2] = {"possible\n","impossible\n"};
    int n = 0, m = 0;
    
    std::cin >> n >> m;
    
    while(n!=0 && m!=0){
        solve(n,m,bills,res);
        std::cin >> n >> m;
    }
    
    return 0;
}
