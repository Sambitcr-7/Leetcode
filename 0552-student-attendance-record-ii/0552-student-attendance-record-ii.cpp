class Solution {
public:
    int checkRecord(int n) {
        // Constants for mod calculation to prevent overflow
        const int mod = 1e9 + 7;

        // dp[absent_count][late_count] = number of valid sequences ending in this state
        long long dp[2][3] = {0}; // '2' for 0 or 1 absent, '3' for late counts (0, 1, 2)
        dp[0][0] = 1; // initial state: no absent, no late
        dp[0][1] = 1; // initial state: no absent, one late
        dp[1][0] = 1; // initial state: one absent, no late

        for (int i = 1; i < n; i++) {
            long long nextDp[2][3] = {0}; // Temporary storage for the next state
            
            // Update states for no absent
            nextDp[0][0] = (dp[0][0] + dp[0][1] + dp[0][2]) % mod; 
            nextDp[0][1] = dp[0][0]; // one late today
            nextDp[0][2] = dp[0][1]; // two consecutive lates today

            // Update states for one absent
            nextDp[1][0] = (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % mod; 
            nextDp[1][1] = dp[1][0]; // one late today
            nextDp[1][2] = dp[1][1]; // two consecutive lates today

            // Copy the temporary array to the main dp array for the next iteration
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[j][k] = nextDp[j][k];
                }
            }
        }

        // Sum up all valid sequences
        int result = 0;
        for (int absent = 0; absent < 2; absent++) {
            for (int late = 0; late < 3; late++) {
                result = (result + dp[absent][late]) % mod;
            }
        }
        return result;
    }
};
