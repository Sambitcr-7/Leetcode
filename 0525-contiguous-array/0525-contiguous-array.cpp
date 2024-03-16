class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         // Initialize an unordered map to store prefix sums and their indices
        unordered_map<int,int> mp;
        
        // Get the size of the input array
        int n = nums.size();
        
        // Initialize variable to store the final answer
        int ans = 0;
        
        // Initialize variable to store the cumulative sum of 0s and 1s encountered so far
        int prefix = 0;
        
        // Set the initial prefix sum of 0 to index -1 (convention for simplifying logic)
        mp[0] = -1;

        // Iterate through each element of the input array
        for(int i = 0; i < n; i++) {
            // Update prefix sum: increment if element is 1, decrement if element is 0
            if(nums[i] == 1)
                prefix++;
            else
                prefix--;
            
            // If the current prefix sum is not found in the map, add it along with its index
            if(mp.find(prefix) == mp.end()) {
                mp[prefix] = i;
            }
            else {
                // If the prefix sum is found in the map, calculate the length of the subarray
                // with equal number of 0s and 1s, and update the answer accordingly
                ans = max(ans, i - mp[prefix]);
            }
        }
        
        // Return the final answer representing the length of the longest contiguous subarray
        // with equal number of 0s and 1s
        return ans;
    }
};