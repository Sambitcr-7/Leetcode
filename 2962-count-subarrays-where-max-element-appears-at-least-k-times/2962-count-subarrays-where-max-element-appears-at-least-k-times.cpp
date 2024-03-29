#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for(auto i:nums){
            maxi =  max(maxi, i);
        }
        int n = nums.size();
        int i=0;
        int j = 0;
        int cnt = 0;
        ll ans = 0;
        while(j<n){
            if(nums[j] == maxi){
                cnt++;
                if(cnt>=k){
                    ans+=(n-j);
                    if(nums[i] == maxi) cnt--;
                    i++;
                    while(cnt>=k){
                        ans+=(n-j);
                        if(nums[i] == maxi) cnt--;
                        i++;
                    }
                }
                
            }
            j++;
        }

        return ans;
    }
};