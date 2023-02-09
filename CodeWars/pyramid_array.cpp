#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> pyramid(std::size_t n) {
  std::vector<std::vector<int>> arr = {};
  for(std::size_t i = 1; i <= n; i++){
    std::vector<int> temp = {};
    for(std::size_t j = 0; j < i; j++){
      temp.push_back(1);
    }
    arr.push_back(temp);
  }
  
  return arr;
}