class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(begin(nums), end(nums));

        unordered_map<int, vector<int>> dp;

        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            dp[i] = {nums[i]};
            for(int j = 0; j < i; j++){
               if(nums[i] % nums[j] == 0){
                   if(dp[i].size() < dp[j].size()+1){
                       dp[i] = dp[j];
                       dp[i].push_back(nums[i]);
                   }
               }
            }
            if(dp[i].size() > ans.size()) ans = dp[i];
        }
        return ans;
    }
};