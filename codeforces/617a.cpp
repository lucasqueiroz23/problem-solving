#include <iostream>

int getNumberOfSteps(int coordinate){
  int numOfSteps = 0, nextMove = 5;
  while(coordinate > 0){
    while(coordinate >= nextMove){
      numOfSteps++;
      coordinate-=nextMove;
    }
    nextMove--;
  }
  return numOfSteps;
}

int main(){
  int friendCoordinate = 0;
  std::cin >> friendCoordinate;
  std::cout << getNumberOfSteps(friendCoordinate) << "\n";
  return 0;
}