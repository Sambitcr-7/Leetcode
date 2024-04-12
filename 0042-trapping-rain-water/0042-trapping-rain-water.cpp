class Solution {
public:
    int trap(vector<int>& a) {
        
        int n=a.size();
        int l=0;
        int r=n-1;
        int res=0;

        int lmax=a[0],rmax=a[n-1];

        while(l<=r){

            if(a[l] <= a[r]){

                if(lmax <= a[l]){
                    lmax=a[l];
                }
                else{
                    res+=lmax-a[l];

                }
                l++;
            }

            else{
                if(rmax <= a[r] ){
                    rmax =a[r];
                }
                else{
                    res+=rmax-a[r];
                }

                r--;
            }
        }

        return res;
    }
};