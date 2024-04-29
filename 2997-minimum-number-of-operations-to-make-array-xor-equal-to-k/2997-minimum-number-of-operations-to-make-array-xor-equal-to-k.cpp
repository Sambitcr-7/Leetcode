class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int num = 0;
        for(int ele : nums){
            num = num ^ ele;
        }
        
        num = num ^ k;
        int count = 0;
        
        while(num > 0){
            if(num & 1)
                count++;
            num = num >> 1;
        }
        
        return count;
    }
};