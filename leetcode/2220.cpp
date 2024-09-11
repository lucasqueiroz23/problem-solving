class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;

        while(goal != 0 || start!= 0) {
            int a = 1 & start;
            int b = 1 & goal;

            if(a != b) {
                count++;
            }

            start >>= 1;
            goal >>= 1;
        }
        

        return count;
    }
};
