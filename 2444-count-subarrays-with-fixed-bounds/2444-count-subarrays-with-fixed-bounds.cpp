class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minkPos = -1, maxkPos = -1;
        long long res = 0;
        int culpritIdx = -1, i = 0;
        while(i<n){
            if(nums[i]==minK)
                minkPos = i;
            
            if(nums[i]==maxK)
                maxkPos = i;
            
            if(nums[i]<minK || nums[i]>maxK)
                culpritIdx = i;
            
            long long smaller = min(minkPos, maxkPos);
            long long temp = smaller - culpritIdx;

            res += (temp<=0) ? 0 : temp; 

            i++;
        }
        return res;
    }
};