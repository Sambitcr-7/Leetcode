class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
         int n = nums.size(), flip_count = 0, current_flips = 0;
        vector<int> is_flipped(n, 0);

        for (int i = 0; i < n; ++i) 
        {
            if (i >= k && is_flipped[i - k]) current_flips--;
            if ((nums[i] + current_flips) % 2 == 0) 
            {
                if (i + k > n) return -1;
                is_flipped[i] = 1;
                current_flips++;
                flip_count++;
            }
        }
        return flip_count;
    }
};