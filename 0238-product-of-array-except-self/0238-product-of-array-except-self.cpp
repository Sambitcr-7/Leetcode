class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int mul = 1, zero = 0, n = nums.size();
        for(auto x : nums){
            if(x == 0) zero++;
            else mul*=x;
        }

        vector<int> ans(n, 0);
        if(zero >= 2) return ans;
        for(int i = 0; i<n; i++){
            if(zero){
                if(nums[i] == 0) ans[i] = mul;
            }else{
                ans[i] = mul/nums[i];
            }
        }
        return ans;
    }
};