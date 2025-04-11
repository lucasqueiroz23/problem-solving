class Solution {
public:
    int sum(string num, int l, int r) {
        int count = 0;
        for(int i = l; i <= r; i++)
            count += num[i];

        return count;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        int pot = 1;
        for(int i = low; i <= high; i++) {
            string num = to_string(i);
            if(sum(num, 0, num.size()/2 - 1) == sum(num, num.size()/2, num.size() - 1))
                count++;
        }
        return count;
    }
};
