class Solution {
public:
    int numSquares(int n) {
        vector<int> v (n + 1, 1e9);
        v[0] = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j*j <= n-i; j++)
                v[i + j*j] = min(v[i+j*j], v[i] + 1);
        return v[n];
    }
};