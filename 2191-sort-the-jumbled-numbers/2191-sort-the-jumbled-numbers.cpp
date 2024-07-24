class Solution {
private:
    int count(int num){
        int ans = 0;
        while(num){
            ans++;
            num /= 10;
        }
        return ans;
    }
    int helper(vector<int> &mapping, int original){
        if(original == 0) return mapping[0];
        int replaced = 0;
        int sz = count(original);
        vector<int> v(sz, 0);
        int idx = 0;
        while(original){
            v[idx] = mapping[original % 10];
            idx++;
            original /= 10;
        }
        for(int i = sz - 1 ; i >= 0 ; i--){
            replaced = replaced*10 + v[i];
        }
        return replaced;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // 0 - 8
        // 1 - 9
        // 2 - 4
        // 3 - 0
        // 4 - 2
        // 5 - 1
        // 6 - 3 
        // 7 - 5
        // 8 - 7
        // 9 - 6
        // 991 - 669 - 0
        // 338 - 007 - 7 - 1
        // 38. - 07. - 7 - 2
        // 338, 38, 991
        // v - ({669, 0}, {7, 1}, {7, 2})
        // v - ({7, 1}, {7, 2}, {669, 0})
        vector<pair<int, int>> v;
        vector<int> ans;
        int sz = nums.size();
        for(int i = 0 ; i < sz ; i++){
            v.push_back({helper(mapping, nums[i]), i});
        }
        sort(v.begin(), v.end());
        for(auto &ele : v) ans.push_back(nums[ele.second]);
        return ans;
    }
};