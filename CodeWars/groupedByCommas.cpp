#include <string>
#include <stack>

std::string group_by_commas(int n) {
  // edge case
  if(n == 0) return "0";
  
  std::stack<char> st;
  int push_count = 0;
  
  const int integer_decimal_ascii_range = 48;
  
  while(n > 0) {
    
    st.push((char) ((n % 10) + integer_decimal_ascii_range)) ;
    
    push_count++;
    
    if(push_count == 3 && n / 10 != 0){ 
      push_count = 0;
      st.push(',');
    }
    n /= 10;
  }
  
  std::string ans = "";
  while(st.size()) {
    ans.push_back(st.top());
    st.pop();
  }
  
  return ans;
  
}
