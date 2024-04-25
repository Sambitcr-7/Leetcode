class Solution {
public:
    int yesRec(int i, char prev, string& s, int k, vector<vector<int>>& dp)
    {
        if (i >= s.size())
            return 0;
        
        if (prev != '`' && dp[i][prev - '`'] != -1)
            return dp[i][prev - '`'];
        
        int notTake = yesRec(i + 1, prev, s, k, dp);

        int take = 0;
        if (prev == '`' || abs(s[i] - prev) <= k)
        {
            take = 1 + yesRec(i + 1, s[i], s, k, dp);
        }
        
        return dp[i][prev - '`'] = max(notTake, take);
    }
    
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(28, -1));

        return yesRec(0, '`', s, k, dp);
    }
};