#include <iostream>
 
int main() {
    
    int p1=0,p2=0;
    std::cin >>p1 >> p2;
    
    if(p1 == 0)
        std::cout <<"C\n";
    if(p1 == 1){
        if(p2==1)
            std::cout <<"A\n";
        if(p2 == 0)
            std::cout <<"B\n";
    }
 
    return 0;
}
