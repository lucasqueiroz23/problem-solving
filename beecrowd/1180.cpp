#include <iostream>
 

void solve(int n){
    int lowest = 2147483647, pos = -1;
    for(int i = 0; i<n;i++){
        int val = 0;
        std::cin >> val;
        if(val < lowest){
            pos = i;
            lowest = val;
        }
    }
    
    std::cout << "Menor valor: " << lowest << "\nPosicao: " << pos <<"\n";
    
}
 
int main() {
    
    int n;
    std::cin >> n;
    
    solve(n);
    
 
    return 0;
}
