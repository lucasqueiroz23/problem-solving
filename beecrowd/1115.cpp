#include <iostream>

void solve(int x, int y){
    if(x>0){
        if(y>0)
            std::cout << "primeiro\n";
        else
            std::cout << "quarto\n";
        return;
    }
    if(y>0)
        std::cout << "segundo\n";
    else
        std::cout << "terceiro\n";
    
}

int main() {
    int x = 0, y = 0;
    std::cin >> x >> y;
    
    while(x!=0 && y!=0){
        solve(x,y);
        std::cin >> x >> y;    
    }
    
    return 0;
}
