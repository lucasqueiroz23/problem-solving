#include <iostream>
 
unsigned long long fib[61];

void initFib()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i<61;i++)
        fib[i] = 0;
}

void solve(int n){
    for(int i = 0; i <= n; i++){
        if(i>1)
            fib[i] = fib[i-1] + fib[i-2];
    }
    
    std::cout << "Fib(" << n << ") = " << fib[n] <<"\n";
}

int main() {
    int t = 0, n = 0;
    std::cin >> t;
    initFib();
    
    while(t>0){
        std::cin >> n;
        solve(n);
        t--;
    }
    
    return 0;
}
