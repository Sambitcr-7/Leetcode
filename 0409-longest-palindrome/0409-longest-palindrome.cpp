class Solution {
public:

    int longestPalindrome(string s) {

        unordered_map<char, int>m;
        for(char c: s)m[c]++;
        
        int p=0;
        bool isOdd=false;

        for(auto iter=m.begin(); iter !=m.end(); iter++) {
            if (iter->second%2==0) {
                p+=iter->second;
            } else {
                if (iter->second % 2 ==1) {
                    isOdd=true;
                    p = p + iter->second-1;
                }
            }
        }

        if (isOdd)return p+1;
        return p;
    }
};