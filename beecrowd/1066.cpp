#include <iostream>

int main() {
    int countPos = 0, countNeg = 0, countEven = 0, countOdd = 0;
    int n = 0;
    for(int i = 1; i<=5 ;i++){
        std::cin >> n;
        if(n>0)
            countPos++;
        if(n<0)
            countNeg++;
        if(n%2 == 0)
            countEven++;
        else
            countOdd++;
    }
    std::cout << countEven << " valor(es) par(es)\n";
    std::cout << countOdd << " valor(es) impar(es)\n";
    std::cout << countPos << " valor(es) positivo(s)\n";
    std::cout << countNeg << " valor(es) negativo(s)\n";

    return 0;
}
