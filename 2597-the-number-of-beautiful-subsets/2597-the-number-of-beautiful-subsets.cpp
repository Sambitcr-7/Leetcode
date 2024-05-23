class Solution {
public:
    int c=0;
    bool check(vector<int> &arr,int k)
    {
        int i=1,n=arr.size(),key;
        if(n==0)return false;
        if(n==1)return true;
        int start,end,mid;
        for(int i=0;i<n;i++)
        {
            key=arr[i]+k;
            start=i;
            end=n-1;
            while(start<=end)
            {
                mid=start+(end-start)/2;
                if(arr[mid]>key)end=mid-1;
                else if(arr[mid]<key)start=mid+1;
                else return false;
            }
        }
        return true;
    }
    void f(int i,vector<int>&nums,vector<int>&vec,int k)
    {
        if(i>=nums.size())
        {
            if(check(vec,k))c++;
            return;
        }
        vec.push_back(nums[i]);
        f(i+1,nums,vec,k);
        vec.pop_back();
        f(i+1,nums,vec,k);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> vec;
        f(0,nums,vec,k);
        return c;
    }
};