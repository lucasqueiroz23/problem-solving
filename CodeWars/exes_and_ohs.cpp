#include <cctype>

bool XO(const std::string& str)
{
  int cntO = 0, cntX = 0;
  
  for(int i = 0; i< str.length(); i++){
    if (tolower(str[i]) == 'x')
      cntX++;
    if(tolower(str[i]) == 'o')
      cntO++;
  }
  if(cntO==cntX)
    return true;
  
  return false;
}
