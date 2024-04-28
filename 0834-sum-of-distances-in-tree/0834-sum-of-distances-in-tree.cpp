class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        vector<int> count(n, 1);
        unordered_map<int, unordered_set<int>> tree;

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].insert(v);
            tree[v].insert(u);
        }

        function<void(int, int)> postorder = [&](int node, int parent) {
            for (int child : tree[node]) {
                if (child == parent) continue;
                postorder(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        };

        function<void(int, int)> preorder = [&](int node, int parent) {
            for (int child : tree[node]) {
                if (child == parent) continue;
                ans[child] = ans[node] - count[child] + (n - count[child]);
                preorder(child, node);
            }
        };

        postorder(0, -1);
        preorder(0, -1);

        return ans;
    }
};