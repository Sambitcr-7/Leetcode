class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
           for(int i=0;i<nums.size();i++){
            nums[i] = nums[i]*nums[i];
        }
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        nums.clear();
        while(pq.size()){
            nums.push_back(pq.top());
            pq.pop();
        }
        return nums;
    }
};