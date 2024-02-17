class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();

        for(int i=0; i<n-1; i++) {
            int diff = heights[i+1] - heights[i];
            // for valid difference between heights 
            if(diff > 0) {
                bricks -= diff;
                pq.push(diff);
                // if all bricks are used
                if(bricks < 0) {
                    // and all ladders are used to, then return the curr index
                    if(ladders <= 0) {
                        return i;
                    } // other wise use ladder to jump to the next height
                    else {
                        bricks += pq.top();
                        pq.pop();
                        ladders--;
                    }
                }
            }
        }
        // if we managed to get the last index, return it here
        return n-1;
    }
};