class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 2; i < n; i += 3) {
            int smaller = nums[i - 2];
            int larger = nums[i];
            if(larger - smaller > k) {
                return {};
            } else {
                ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
            }
        }
        return ans;
    }
};