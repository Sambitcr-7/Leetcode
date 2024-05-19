class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        long long res=0;
        long changes=0;
        int mindiff=INT_MAX;
        for(int num:nums){
            int xornum=num^k;
            if(num<xornum){
                changes++;
                res+=xornum;
            }
            else{
                res+=num;
            }
            mindiff=min(mindiff,abs(num-xornum));
        }
        if(changes%2==0){
            return res;
        }
        else{
            return res-mindiff;
        }
    }
};