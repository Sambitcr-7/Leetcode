class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int,vector<pair<int,int > > >adj;
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        k++;
        while(k--){
            int size=q.size();
            while(size--){
                int currprice=q.front().second;
                 for(auto& x:adj[q.front().first]){
                     int newprice=currprice+x.second;
                     if(newprice <distance[x.first])
                     {
                         distance[x.first]=newprice;
                         q.push({x.first,newprice});
                     }
                 }
                 q.pop();
            }
        }
        return (distance[dst] ==  INT_MAX )?-1:distance[dst];
    }
};