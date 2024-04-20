class Solution {
public:
    int m, n;
    std::vector<std::pair<int, int>> directions{
        {0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    void DFS(int i, int j, std::vector<std::vector<int>>& land, int& lastRow,
             int& lastCol) {
        if (i >= m || i < 0 || j >= n || j < 0 || land[i][j]==0)
            return;

        land[i][j] = 0;
        lastRow = std::max(i, lastRow);
        lastCol = std::max(j, lastCol);
        for (auto p : directions)
            DFS(i + p.first, j + p.second, land, lastRow, lastCol);
    }
    std::vector<std::vector<int>>
    findFarmland(std::vector<std::vector<int>>& land) {
        m = land.size(), n = land[0].size();
        std::vector<std::vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0)
                    continue;

                int lastRow = i, lastCol = j;
                DFS(i, j, land, lastRow, lastCol);
                result.push_back({i, j, lastRow, lastCol});
            }
        }
        return result;
    }
};