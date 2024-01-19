class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A[0].size();
        int dp[n][n];
        for(int j=0;j<n;j++) dp[0][j]=A[0][j];
        int ans=INT_MAX;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>0 && j<n-1)
                {
        dp[i][j]=min(dp[i-1][j-1]+A[i][j],dp[i-1][j]+A[i][j]);
        dp[i][j]=min(dp[i][j],A[i][j]+dp[i-1][j+1]);
                }
                else if(j==0)
                {
        dp[i][j]=min(dp[i-1][j]+A[i][j],A[i][j]+dp[i-1][j+1]);
                }
                else if(j==n-1)
                {
        dp[i][j]=min(dp[i-1][j]+A[i][j],A[i][j]+dp[i-1][j-1]);
                }
            }
        }
        for(int j=0;j<n;j++) ans=min(ans,dp[n-1][j]);
        return ans;
    }
};