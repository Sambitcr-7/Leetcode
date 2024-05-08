class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> answer(n);
        unordered_map<int, int> mp;

        // Mapping score to their respective indices
        for (int i = 0; i < n; ++i) {
            mp[score[i]] = i;
        }

        // Sorting the scores in descending order
        sort(score.rbegin(), score.rend());

        // Assigning ranks based on sorted scores
        for (int i = 0; i < n; ++i) {
            int idx = mp[score[i]];
            if (i == 0) {
                answer[idx] = "Gold Medal";
            } else if (i == 1) {
                answer[idx] = "Silver Medal";
            } else if (i == 2) {
                answer[idx] = "Bronze Medal";
            } else {
                answer[idx] = to_string(i + 1);
            }
        }

        return answer;
    }
};