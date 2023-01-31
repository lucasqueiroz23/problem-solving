#include <iostream>

int soldierMoney, desiredAmountOfBananas, costOfFirstBanana;

int getTotalPrice(){
  int total = 0;
  for(int i = 1; i <= desiredAmountOfBananas; i++ ){
    total += i*costOfFirstBanana;
  }
  return total;
}

int getAmountToBorrow(int costOfBananas){
  return costOfBananas <= soldierMoney ? 0 : costOfBananas - soldierMoney;
}


int main(){

  std::cin >> costOfFirstBanana >> soldierMoney >> desiredAmountOfBananas;
  std::cout << getAmountToBorrow(getTotalPrice()) << "\n";
  return 0;
}