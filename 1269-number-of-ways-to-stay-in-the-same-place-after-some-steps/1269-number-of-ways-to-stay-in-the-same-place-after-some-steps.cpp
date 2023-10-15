class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>> dp;
       int f(int steps, int i, int n) {//(remaining moves, index, n)
        if (steps==0) 
            return (i==0) ? 1 : 0;

        if (dp[steps][i]!= -1) 
            return dp[steps][i];

        long long ans=f(steps-1, i, n) %mod;//stay

        // Move to the right 
        if (i<n-1) 
            ans= (ans+f(steps-1, i+1, n))%mod;

        // Move to the left 
        if (i>0) 
            ans = (ans+f(steps-1, i-1, n))%mod;
         
        return dp[steps][i]=ans;
    }

    int numWays(int steps, int arrLen) {
        int n=min(steps/2+1, arrLen);//maximial position can reached
        dp.assign(steps+1, vector<int>(n+1, -1));
        return f(steps, 0, n);
    }
};