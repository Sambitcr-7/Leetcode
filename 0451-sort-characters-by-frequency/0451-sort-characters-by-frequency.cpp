class Solution {
public:
    string frequencySort(string s) {
        int cnt[124]={0};
        for(auto c : s) cnt[c]++;

        sort(s.begin(),s.end(),[cnt](char &a, char &b)->bool {if (cnt[a]==cnt[b]) return a<b; return(cnt[a]>cnt[b]);});
        return s;
        
    }
};