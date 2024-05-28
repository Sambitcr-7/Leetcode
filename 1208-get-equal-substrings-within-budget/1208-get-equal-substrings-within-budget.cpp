class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int window = 0, end = 0, ans = 0, n = s.length(), lenOfWindow = 0;

        while(window < n && end - window <= lenOfWindow){
            while(end < n && abs(s[end] - t[end]) <= maxCost){
                lenOfWindow++;
                maxCost -= abs(s[end] - t[end]);
                end++;
            }

            ans = max(ans, lenOfWindow);

            window++;
            lenOfWindow--;

            if(end < window){
                end = window;
                lenOfWindow = 0;
            }
            else
                maxCost += abs(s[window-1] - t[window-1]);
        }

        return ans;
    }
};