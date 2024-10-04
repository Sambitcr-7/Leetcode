class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(), s.end());
        long long chem{0}, total = accumulate(s.begin(), s.end(), 0LL) / (s.size() / 2);
        for (int i{0}, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] + s[j] != total) return -1;
            chem += 1LL * s[i] * s[j];
        }
        return chem;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();