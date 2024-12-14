class Solution {
public:
    typedef struct data {
        int val;
        int pos;
    }data ;

    struct {
        bool operator()(data& a, data& b) {
            if(a.val == b.val) {
                return a.pos < b.pos;
            }

            return a.val < b.val;
        }
    }compareData;   

    long long findScore(vector<int>& nums) {
        long long score = 0;

        vector<data> d;

        for(int i = 0; i < nums.size(); i++) {
            d.push_back({nums[i], i});
        }

        sort(d.begin(), d.end(), compareData);

        for(int i = 0; i < d.size(); i++) {
            int pos = d[i].pos;
            if(nums[pos] != 0) {
                score += d[i].val;
                
                nums[pos] = 0;
                if(pos + 1 < d.size()) {
                    nums[pos + 1] = 0;
                }

                if(pos - 1 >= 0) {
                    nums[pos - 1] = 0;
                }
            }
        }


        return score;
    }
};
