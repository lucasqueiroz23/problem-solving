#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> appearences;
        for(int num : nums) {
            if(!appearences[num]) appearences[num] = 1;
            else return true;
        }
        return false;
    }
};
