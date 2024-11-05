class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(nums2.size() == 0) return;

        int i = 0, j = 0;

        while(i < m && j < n) {
            if(nums2[j] < nums1[i]) {
                int temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;

                int x = j;
                while(x + 1 < n && nums2[x] > nums2[x+1]) {
                    int temp = nums2[x];
                    nums2[x] = nums2[x+1];
                    nums2[x+1] = temp;
                    x++;
                }

            } 
            i++;
        }

        while(i < m) {
            nums1[i++] = nums2[j++];
        }
        
        while(j < n) {
            nums1[i++] = nums2[j++];
        }
    }
};
