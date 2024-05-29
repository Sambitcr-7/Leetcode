class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int cnt=0;
        int carry=0;
        for(int i=n-1;i>0;i--){
            if(s[i]=='1'){
                if(carry==1){
                    cnt+=1;
                }
                else{
                    cnt+=2;
                    carry=1;
                }
            }
            else{
                if(carry==1){
                    cnt+=2;
                }
                else{
                    cnt+=1;
                }
            }
        }
        return cnt+carry;
        
    }
};