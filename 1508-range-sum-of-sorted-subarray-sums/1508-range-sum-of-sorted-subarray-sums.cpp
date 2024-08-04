class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // n ( n -  1) (n - 2) ... 1
        // 1 + 2 + 3 + ... + (n - 2) + (n - 1) + n
        // n * (n + 1) / 2
        // 1 2 3 4 5
        // i = 0, j = i to 5 
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0 ; i < n ; i++){
            int currItrSum = 0;
            for(int j = i ; j < n ; j++){
                currItrSum += nums[j];
                pq.push(currItrSum);
            }
        }
        int total = right - left + 1;
        left--;
        while(left--){
            pq.pop();
        }
        int mod = 1e9 + 7;
        int sum = 0;
        while(total--){
            sum += pq.top();
            sum %= mod;
            pq.pop();
        }
        return sum;
    }
};