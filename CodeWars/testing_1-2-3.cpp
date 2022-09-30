#include <string>
#include <vector>

std::vector<std::string> number(const std::vector<std::string> &lines)
{ 
  std::vector<std::string> res = {};
  
  for(int i = 0; i<lines.size(); i++){
    std::string str = "";
    str += std::to_string(i+1) + ": " + lines[i];
    res.push_back(str);
  }
  
  return res;
}
