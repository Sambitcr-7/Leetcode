#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int minCost(string& colors, vector<int>& neededTime) {
        int l=0, r, n=colors.size();
        int removes=0, locMax=0;
        for (r=0; r<n; ) {
            while (r<n && colors[r]==colors[l]) {
                removes+=neededTime[r];
                locMax=max(locMax, neededTime[r]);
                r++;
            }
        //    cout << "l=" << l << " locMax=" << locMax << endl;
            removes-= locMax;
            locMax=0;
            l=r; 
        }
        return  removes;
    }
};