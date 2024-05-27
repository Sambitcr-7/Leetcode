class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
int n=nums.size();
        for(int i=1;i<=1000;i++){
            int idx=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if((n-idx)==i)return i;
        }
        return -1;
    }
};