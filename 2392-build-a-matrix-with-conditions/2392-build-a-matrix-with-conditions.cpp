class Solution {
    bool dfs(int curr, vector<int> adjList[], vector<char> &visited, vector<int> &order) {
        visited[curr] = 'G';
        for(int next: adjList[curr]) {
            if(visited[next] == 'W') {
                if(dfs(next, adjList, visited, order)) return true;
            } else if(visited[next] == 'G') {
                return true;
            }
        }
        visited[curr] = 'B';
        order.push_back(curr);
        return false;
    }
    vector<int> topologicalSort(vector<vector<int>> &edges, int n) {
        vector<int> adjList[n + 1], order;
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        vector<char> visited(n + 1, 'W');
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 'W')
                if(dfs(i, adjList, visited, order)) return {};
        }
        reverse(order.begin(), order.end());
        return order;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowTopoOrder = topologicalSort(rowConditions, k);
        vector<int> colTopoOrder = topologicalSort(colConditions, k);
        if(rowTopoOrder.empty() || colTopoOrder.empty()) return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(rowTopoOrder[i] == colTopoOrder[j])
                    ans[i][j] = rowTopoOrder[i];
            }
        }
        return ans;
    }
};