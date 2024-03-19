class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
             int m = tasks.size();
        int frequency[26] = {0};
        for (const auto& task : tasks) {
            frequency[task - 'A']++;
        }
        int max_frequency_count = 0;
        int max_frequency = 0;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > max_frequency) {
                max_frequency = frequency[i];
                max_frequency_count = 1;
            } else if (frequency[i] == max_frequency) {
                max_frequency_count++;
            }
        }
        return max(m, (max_frequency - 1) * (n + 1) + max_frequency_count);
    }
};