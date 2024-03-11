class Solution {
public:
    string customSortString(string order, string s) {
    ios_base::sync_with_stdio(false);
    
    if(order.size() == 0) return s;
    vector<int> mpp(26,0);
    for (char c : s) {
            mpp[c - 'a']++;
    }
    string ans="";
    int j=0;
    while(j < order.size())
    {
        if(mpp[order[j] - 'a'] != 0)
        {
            ans=ans+order[j];
            mpp[order[j] -'a']--;
        }
        else{
            j++;
        }
    }
    for(int i=0;i < s.size();i++)
    {

        if(mpp[s[i]-'a'] != 0)
        {
            ans=ans+s[i];
        }
    }
    return ans;
    }
};