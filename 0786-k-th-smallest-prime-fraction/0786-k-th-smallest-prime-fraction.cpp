class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;
        int n = arr.size();
        bool f=true;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                double dv = (double)(arr[i]) / (double)(arr[j]);
                // cout<<"dv-> "<<dv<<endl;
                pq.push({dv, {arr[i], arr[j]}});
            }
        }
        //   while(!pq.empty()){
        //     auto it=pq.top();
        //     pq.pop();
        //     cout<<"dv-> "<<it.first<<" :: first-> "<<it.second.first<<" ::
        //     second-> "<<it.second.second<<endl;
        //   }
        k--;
        while (k--) {
            auto it = pq.top();
            pq.pop();
            // cout << "dv-> " << it.first << " :: first-> " << it.second.first
            //      << " :: second-> " << it.second.second << endl;
        }
        auto it = pq.top();
        return {it.second.first, it.second.second};
    }
};