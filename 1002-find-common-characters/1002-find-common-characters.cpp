class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> arr(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                int ch = words[i][j]-'a';
                arr[i][ch]++;
            }
        }
        vector<string> ans;
        for(int j=0;j<26;j++){
            int mini = INT_MAX;
            for(int i=0;i<n;i++){
                mini = min(mini,arr[i][j]);
            }
            while(mini--){
                string str = "";
                str += 'a'+j;
                ans.push_back(str);
            }
        }
        return ans;
    }
};