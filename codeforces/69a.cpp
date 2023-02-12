#include <iostream>
#include <string>

int n;
int sumOfForces[3] = {0, 0, 0};

void getForceVector(){
  int coordinate = 0;
  for(int i = 0; i < 3; i++){
    std::cin >> coordinate;
    sumOfForces[i] += coordinate;
  }
}

std::string bodyIsIdle(){
  for(int i = 0; i < 3; i++){
    if(sumOfForces[i] != 0){
      return "NO\n";
    }
  }
  return "YES\n";
}

int main(){
  std::cin >> n;

  while(n--){
    getForceVector();
  }

  std::cout << bodyIsIdle();

  return 0;
}