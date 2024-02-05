class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<int>v(26,-1);
        for(int i=0;i<s.size();i++)
        {
            if(v[s[i]-'a']==-1)v[s[i]-'a']=i;
            else v[s[i]-'a']=-2;
        }    
        int mini=INT_MAX;
        for(auto i:v)
        {
            if(i!=-1&&i!=-2)
            {
                mini=min(mini,i);
            }
        }
        if(mini==INT_MAX)return -1;
        return mini;
    }
};