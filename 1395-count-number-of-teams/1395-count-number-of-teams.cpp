class Solution {
public:
    int numTeams(vector<int>& rating) {
        // 2 5 3 4 1
        // Condition - 1
        // 2 3 4
        // Condition - 2
        // 5 3 1
        // 5 4 1
        // Smallest numbers and largest numbers
        // Rating   : 2 5 3 4 1  // x 3 4 - 1
        // Smallest : 0 1 1 2 0  // x 3 1 - 1
        // Largest  : 0 0 1 1 4  // x 4 1 - 1
        int n = rating.size();
        vector<int> smallest(n, 0);
        vector<int> largest(n, 0);
        for(int i = 0 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(rating[i] > rating[j]) smallest[i]++;
                if(rating[i] < rating[j]) largest[i]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(rating[i] > rating[j]) ans += smallest[j];
                if(rating[i] < rating[j]) ans += largest[j];
            }
        }
        return ans;
    }
};