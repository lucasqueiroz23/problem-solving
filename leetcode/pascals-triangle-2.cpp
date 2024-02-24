class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.push_back({1});

        for(int i = 1; i < numRows; i++) {
            vector<int> new_arr = {1};
            for(int j = 1; j < i ; j++) {
                new_arr.push_back(ret[i-1][j] + ret[i-1][j-1]);
            }
            new_arr.push_back(1);
            ret.push_back(new_arr);
        }


        return ret;
    }

    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle = this->generate(rowIndex + 1);
        return triangle[rowIndex];
    }
};
