class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int cnt = 0;
        int i = 0;
        int n = t.size();
        while(n > 0) {
            if(t[i] == 0) {
                t.erase(t.begin() + i);
    
                if(i < k) k--;
                n--;
                i--;
            } 
            else {
                t[i]--;
                cnt++;
                if(i == k && t[i] == 0) return cnt;
            }
            i++;
            if(i == n) i = 0;
        }
        return cnt;
    }
};