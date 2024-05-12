class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int n = grid.size();
        int maxi = 0;
        for(int i=0; i<n-2; i++){
            vector<int> temp;
            for(int j=0; j<n-2; j++){
                for(int k=i; k<i+3; k++){
                    for(int l=j; l<j+3; l++){
                        maxi = max(maxi, grid[k][l]);
                    }
                }
                temp.push_back(maxi);
                maxi=0;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};