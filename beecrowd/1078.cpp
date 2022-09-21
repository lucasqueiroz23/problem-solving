#include <iostream>

int main() {
    int N = 0;
    std::cin >> N;
    for(int mult = 1; mult<=10; mult++)
        std::cout <<mult<<" x "<<N<<" = " << mult*N << "\n";
 
    return 0;
}
