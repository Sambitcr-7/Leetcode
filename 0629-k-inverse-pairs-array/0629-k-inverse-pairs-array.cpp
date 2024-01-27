/*
    if we put n as the last number then all the k inverse pair should come from the first n-1 numbers
if we put n as the second last number then there's 1 inverse pair involves n so the rest k-1 comes from the first n-1 numbers
...
if we put n as the first number then there's n-1 inverse pairs involve n so the rest k-(n-1) comes from the first n-1 numbers

dp[n][k] = dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]+dp[n-1][k-n+1]

It's possible that some where in the right hand side the second array index become negative, since we cannot generate negative inverse pairs we just treat them as 0, but still leave the item there as a place holder.

dp[n][k] = dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]+dp[n-1][k-n+1]
dp[n][k+1] = dp[n-1][k+1]+dp[n-1][k]+dp[n-1][k-1]+dp[n-1][k-2]+...+dp[n-1][k+1-n+1]
*/

class Solution {
public:
    const int MOD = (int)1e9 + 7;
    typedef long long int64;
    int kInversePairs(int n, int k) {
        if(k > n * (n - 1) / 2 || k < 0) {
            return 0;
        }
        if(k == 0 || k == n * (n - 1) / 2) return 1;
        int64 dp[n + 1][k + 1]; // dp[n][k] denotes the number of arrays that have k inverse pairs for array composed of 1 to n
        memset(dp, 0LL, sizeof(dp));
        dp[2][0] = 1;
        dp[2][1] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i][0] = 1;
            for(int j = 1; j <= min(k, i * (i - 1) / 2); j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                if(j >= i) {
                    dp[i][j] -= dp[i - 1][j - i];
                }
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }
        return dp[n][k];
    }
};