class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> ans;
        for(auto c : nums){
            int ind = abs(c)-1;
            if(nums[ind] < 0 ) ans.push_back(abs(c));
            else nums[ind]=-nums[ind];
        }
        return ans;
    }
};