#include <iostream>
#include <iomanip>

 
int main() {
    int qtdPos = 0;
    float media = 0;
    for(int i = 0; i< 6; i++){
        float val = 0;
        std::cin >> val;
        if(val>0){
            qtdPos++;
            media+=val;
        }
    }
    
    media/=qtdPos;
    std::cout << qtdPos <<" valores positivos\n"<<std::fixed <<std::setprecision(1) << media<<"\n";
    
    
    return 0;
}
