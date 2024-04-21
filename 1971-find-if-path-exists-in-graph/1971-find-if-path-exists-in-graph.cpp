class Solution {
public:

bool dfs( vector<int>&vis,int i, int des,vector<int> adj[],int sc)
{

    if(i==des)
    return true;
    vis[i]=1;

    for(auto k:adj[i])
    {
        if(!vis[k])
        {
            
        if(dfs(vis,k,des,adj,sc))
        return true;
        }
    
    }
    
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        

        vector<int>adj[n];
        int p=edges.size();

        for(int i=0;i<p;i++)
        {
            int p1=edges[i][0];
            int p2=edges[i][1];
            adj[p1].push_back(p2);
            adj[p2].push_back(p1);
        }

        vector<int>vis(n,0);

        
                return dfs(vis,source,destination,adj,source);
           
    
    }
};