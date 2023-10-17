class DisjointSet{
    vector<int>parent;
    public:
    DisjointSet(int n){
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findUpar(int n){
        if(n==parent[n]){
            return n;
        }
        return parent[n]= findUpar(parent[n]);
    }
    void unionBySize(int x, int y){
        int px = findUpar(x);
        parent[y]=px;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet ds(n+1);
        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                if(ds.findUpar(i)==ds.findUpar(leftChild[i])){
                    return false;
                }
                else{
                    ds.unionBySize(i, leftChild[i]);
                }
            }
            if(rightChild[i]!=-1){
                if(ds.findUpar(i)==ds.findUpar(rightChild[i])){
                    return false;
                }
                else{
                    ds.unionBySize(i, rightChild[i]);
                }
            }
        }
        for(int i=0; i<(n-1); i++){
            if(ds.findUpar(i)!=ds.findUpar(i+1)){
                return false;
            }
        }
        return true;
    }
};