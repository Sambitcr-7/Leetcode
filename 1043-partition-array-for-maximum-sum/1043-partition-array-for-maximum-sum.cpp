class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       
          int n=arr.size();
          vector<int> dp(n+1,0);

          for(int i=n-1;i>=0;i--){
              int len=0;
              int maxo=-1e9;
              int mx=-1e9;

              for(int j=i;j<min(i+k,n);j++){
                  len++;
                  maxo=max(maxo,arr[j]);
                  int sum=len*maxo+ dp[j+1];
                  mx=max(mx,sum);
              }
              dp[i]=mx;
          }

          return dp[0]; 
    }
};