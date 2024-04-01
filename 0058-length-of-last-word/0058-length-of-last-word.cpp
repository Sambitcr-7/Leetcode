class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0, f=0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]!=' '){
                c++;
                f=1;
            }else if(f==1 && s[i]==' '){
                break;
            }
        }
        return c;
    }
};