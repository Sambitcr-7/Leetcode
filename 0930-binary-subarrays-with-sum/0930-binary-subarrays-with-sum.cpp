class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        short n = nums.size(), m;
        short i, last = 0;

        vector<short> spaces;
        // spaces has the (count of 0's between 1's and the begin/end of nums) + 1.
        // + 1 it's necessary because none 0s between characters its still a validy choice, intead of count as 0.

        // [0,0,0,0,0] it's equals to spaces [] = {6}           (6 chars + 1)
        // [1,0,1,0,1] it's equals to spaces [] = {1, 2, 2, 1}  (0 chars + 1, 1 chars + 1, 1 chars + 1, 0 chars + 1)
        // ...

        for (i = 0; i < n; i++) {
            if (!nums[i])
                continue;
            spaces.push_back(i - last + 1);
            last = i + 1;
        }
        spaces.push_back(n + 1 - last);
        m = spaces.size();

        if (goal >= m)
            return 0;

        if (goal == 0) {
            for (i = 0; i < m; i++)
                count += (spaces[i] - 1) * spaces[i] / 2;
            return count;
        }

        // get the ranges that match, multiply the begining and end points and add
        // all together. This step it's basically the rule of products with possible
        // begining and end points... 
        // e.g. with {1, 2, 2, 1}
        //            1, 2, 2       from 0 to 2      1 * 2 +
        //               2, 2, 1    from 1 to 3      2 * 1 = 4

        
        for (i = 0; i < m - goal; i++)
            count += spaces[i] * spaces[i + goal];

        return count;
    }
};