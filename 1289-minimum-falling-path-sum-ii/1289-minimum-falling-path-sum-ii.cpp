class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=1; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int temp = INT_MAX;
                for (int k=0; k<n; ++k) {
                    if (j != k) {
                        temp = min(temp, matrix[i - 1][k]);
                    }
                }
                matrix[i][j] += temp;
            }
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};