class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0,high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                return true;
            }
            
            // here we are trimming down the array  
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++,high--;
                continue;
            }
            // identify the sorted half righ // left
            // left sorted
            if(nums[low] <= nums[mid]){
                // target lies within you 
                if(nums[low] <= target && target <= nums[mid]){
                    // remove the righ half
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            // righ sorted
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    // remove left half
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false; 
    }
};