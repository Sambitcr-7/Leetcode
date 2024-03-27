class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         if (k < 2) {return 0;}
        int res = 0;
        int cur_prod = 1;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            cur_prod *= nums[r];
            while (cur_prod >= k) {
                cur_prod /= nums[l];
                l += 1;
            }
            res += (r - l + 1);
        }
        return res;
    }
};