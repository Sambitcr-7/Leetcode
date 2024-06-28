class Solution {
public:
    // time/space: O(nlogn)/O(n)
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // calculate the in/out-degree (the number of the connected roads) for each city
        vector<int> degrees(n, 0);
        for (auto& road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }

        // push the degrees into a min. heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& degree : degrees) minHeap.push(degree);

        // greedy: pair the value from `1` to `n` with the degrees from smaller to bigger
        long long importance = 0LL;
        for (int city = 1; city <= n; city++) {
            importance += (1LL * city * minHeap.top());
            minHeap.pop();
        }
        return importance;
    }
};