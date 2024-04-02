class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        vector<int> PosS(256,-1);
        vector<int> PosT(256,-1);

        for(int i = 0 ; i<s.length() ; i++)
        {
            if(PosS[s[i]]!=PosT[t[i]])
                return false;

            else{
                PosS[s[i]] = i ;
                PosT[t[i]] = i;
            }
        }
        return true;
        
    }
};