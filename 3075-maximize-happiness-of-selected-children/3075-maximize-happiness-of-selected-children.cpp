class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       long long int ans=0;
        sort(happiness.rbegin(),happiness.rend());
        for(int i=0;i<k;i++)
        {
            if(happiness[i]<=i)
                return ans;
            else
                ans+=(happiness[i]-i);
        }
        return ans;
    }
};