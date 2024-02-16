class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mpp;
        for(int i = 0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty() && k>0){
            int x = pq.top().first;
            int y = pq.top().second;
            if(x == 1){
                pq.pop();
            }
            else{
                pq.pop();
                pq.push({--x,y});
            }
            k--;
        }
        return pq.size();
    }
};