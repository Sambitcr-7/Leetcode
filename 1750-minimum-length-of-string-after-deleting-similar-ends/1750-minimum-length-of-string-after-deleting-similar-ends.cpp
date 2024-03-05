class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left=0, right=n-1;
        while(left<right && s[left]==s[right]){
            if(s[left]==s[right]){
                do{
                    left++;
                }while(left<n && s[left]==s[left-1]);
                do{
                    right--;
                }while(right>=0 && s[right]==s[right+1]);
            }
        }
        int ans;
        if(left>right){
            ans=0;
        }
        else if(left==right){
            ans=1;
        }
        else{
            ans = right-left +1;
        }
        return ans;
    }
};