class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> mat(n,vector<int>(m,0));

        int i = 0;
        int j =0;

        while(i<n && j<m){

            mat[i][j] = min(rowSum[i],colSum[j]);

            rowSum[i] = rowSum[i] - mat[i][j];
            colSum[j] = colSum[j] - mat[i][j];

            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
            
        }

        return mat;
        
    }
};