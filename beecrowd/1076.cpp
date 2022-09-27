#include <iostream>
 

 
int main() {
    int n = 0;
    std::cin >> n;
    for(int i = 2; i<=n;i+=2){
        std::cout << i <<"^2 = " << i*i <<"\n";
    }
 
    return 0;
}
