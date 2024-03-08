class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
           vector<int>arr(101,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        sort(arr.begin(),arr.end(),greater<int>());
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==arr[0]){sum+=arr[i];}
            else{break;}
        }
        return sum;
    }
};