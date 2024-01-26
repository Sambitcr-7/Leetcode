class Solution {
public:
    int mod = 1e9 +7;
    int helper(int m, int n, int maxMove, int currRow, int currColumn, unordered_map<string, int>& map){
        if(currRow<0 || currRow>=m || currColumn<0 || currColumn>=n) return 1;
        if(maxMove<=0) return 0;
        string curr = to_string(currRow)+" - "+to_string(currColumn)+" - "+to_string(maxMove);
        if(map.find(curr)!=map.end()) return map[curr];
        int left = helper(m, n, maxMove-1, currRow, currColumn-1, map)%mod;
        int up = helper(m, n, maxMove-1, currRow-1, currColumn, map)%mod;
        int right = helper(m,n, maxMove-1, currRow, currColumn+1, map)%mod;
        int down = helper(m,n, maxMove-1, currRow+1, currColumn, map)%mod;
        map[curr]=(((((left%mod+up%mod)%mod)+right%mod)%mod)+down%mod)%mod;
        return map[curr]%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        unordered_map<string, int> map;
        return helper(m, n, maxMove, startRow, startColumn, map);
        
    }
};