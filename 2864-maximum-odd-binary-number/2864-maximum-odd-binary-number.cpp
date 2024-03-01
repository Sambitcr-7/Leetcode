class Solution {
public:
    string maximumOddBinaryNumber(string s) {
         int n = s.length();
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '1')
            {
                swap(s[i],s[n - 1]);
                break;
            }
        }
        return s;
    }
};