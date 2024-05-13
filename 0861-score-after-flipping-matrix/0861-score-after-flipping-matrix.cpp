class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        // row transformation of matrix
        for (int i = 0; i < grid.size(); i++) {
            // check if first element  is 1 or 0
            // if first element is 0 swap in whole row
            if (grid[i][0] == 0) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 0) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            }
        }

        // for column check no of zeros in more then half of len of row (no of
        // zeros > m/2)
        for (int j = 1; j < grid[0].size(); j++) {
            // count no of zero's
            int count_zero = 0;
            for (int i = 0; i < grid.size(); i++) {
                if (grid[i][j] == 0)
                    count_zero++;
            }
            if (count_zero > grid.size() / 2) {
                for (int i = 0; i < grid.size(); i++) {
                    if (grid[i][j] == 1)
                        grid[i][j] = 0;
                    else
                        grid[i][j] = 1;
                }
            }
        }
        int sum=0;
        // count the no's to binary form
        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]){
                    sum+=pow(2,grid[0].size() - 1 - j);
                }
            }
        }
        return sum;
    }
};