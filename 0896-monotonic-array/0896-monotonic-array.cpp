class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag=true,flag1=true;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            flag=false; 
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            flag1=false; 
        }
        if(flag==true)
            return flag;
        else if(flag1==true)
            return flag1;
        else
            return false;
    }
};