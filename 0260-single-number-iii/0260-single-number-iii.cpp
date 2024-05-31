class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans = ans^nums[i];
        }
        int ind = 0;
        vector<int> res;
        for(int i = 0; i<31; i++){
            if(ans & (1<<i)){
                ind = i;
                break;
            }
        }

        int x1 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] & (1<<ind)){
                x1 ^= nums[i];
            }
        }
        res.push_back(x1);
        res.push_back(ans^x1);
        if(res[0] > res[1]) swap(res[0], res[1]);
        return res;
    }
};