class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize){
            return false;
        }
        map<int, int> cnt;
        for(auto it : hand){
            cnt[it]++;
        }
        for(auto it : cnt){
            int x = it.first;
            int y = it.second;
            if(y){
                for(int j = x; j < (x + groupSize); ++j){
                    if(cnt[j] < y){
                        return false;
                    }
                    cnt[j] -= y;
                }
            }
        }
        return true;
    }
};