class Solution {
public:
    const long long mod = 1e9+7;

    int numOfArrays(int n, int m, int k) {
        int dp[51][101][51]={0}; // (n, maxN, cost)
        int sum[51][101][51]={0}; //sum[n][maxN][cost]=sum_{1<=i<maxN}dp[n][i][cost]
        memset(dp, 0, sizeof(dp)); //must be initialized
        memset(sum, 0, sizeof(sum));
        #pragma unroll
        for (int i=1; i<=m; i++){
            dp[1][i][1]=1;
            sum[1][i][1]+=sum[1][i-1][1]+1;
        }
        #pragma unroll
        for (int sz=1; sz<=n; sz++){
            for(int maxN=1; maxN<=m; maxN++){
                for(int cost=1; cost<=k; cost++){
                    long long ans=((long long)maxN*dp[sz-1][maxN][cost])%mod;
                    ans=(ans+sum[sz-1][maxN-1][cost-1])%mod;
                    dp[sz][maxN][cost]=(dp[sz][maxN][cost]+ans)%mod;
                    sum[sz][maxN][cost]=(sum[sz][maxN-1][cost]+dp[sz][maxN][cost])%mod;
                }
            }
        }     
        return sum[n][m][k];
    }
};