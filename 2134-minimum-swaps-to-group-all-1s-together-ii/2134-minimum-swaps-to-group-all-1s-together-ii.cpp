class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //since array is circular, create a copy of the array and append it again to the end
        //this trick works for all circular arrays
        vector<int> copy(nums);
        int count1 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count1++;
            }
            copy.push_back(nums[i]);
        }
        //sliding window of size(count1) for the first window
        int cur=0;
        for(int i=0;i<count1;i++){
            if(copy[i]==1){
                cur++;
            }
        }
        int ans = count1-cur;
        //sliding window for rest of the vector
        for(int i=1;i<nums.size();i++){
            if(copy[i-1]==1){
                cur--;
            }
            if(copy[i+count1-1]==1){
                cur++;
            }
            ans = min(ans,count1-cur);
        }
        return ans;
    }
};