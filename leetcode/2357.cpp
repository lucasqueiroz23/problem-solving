#include <map>

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> m;
        
        for(int num : nums) {
            if(num != 0)
                m[num]++;
        }

        int carry = 0;
        int count = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            int num = it->first - carry;
            carry += num;
            count++;
        }

        return count;
    }
};
