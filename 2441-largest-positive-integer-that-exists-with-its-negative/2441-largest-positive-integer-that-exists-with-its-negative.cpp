class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0,high=nums.size()-1;
        while(start<high){
            if(nums[start]+nums[high]==0){
                return nums[high];
            }
            else if(nums[start]+nums[high]>0){
                high--;
            }
            else{
                start++;
            }
        }
        return -1;
    }
};