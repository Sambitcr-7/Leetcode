class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> reach(n + 1, 0);
        for(int i = 0; i < ranges.size(); ++i) {
            if(ranges[i] == 0) continue;
            int leftBound = max(0, i - ranges[i]);
            reach[leftBound] = max(reach[leftBound], i + ranges[i]);
        }
        
        int endPos = 0, farthestReach = 0, tapCount = 0;
        for(int i = 0; i <= n; ++i) {
            if(i > endPos) {
                if(farthestReach <= endPos) return -1;
                endPos = farthestReach;
                ++tapCount;
            }
            farthestReach = max(farthestReach, reach[i]);
        }
        
        return tapCount + (endPos < n); 
    }
};