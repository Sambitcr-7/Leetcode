class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int odd=pallin(s,i,i);
            int even=pallin(s,i,i+1);
            ans+=odd+even;
        }
        return ans;
    }

    int pallin(string s,int left,int right){
        int c=0;
        while((left>=0 && right<=s.length()) && s[left]==s[right]){
            left--;
            right++;
            c++;
        }
        return c;
    }

};