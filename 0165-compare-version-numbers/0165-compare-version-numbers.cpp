class Solution {
public:
    vector<int> map_vector(const string &version) {
        vector<int> val;
        istringstream ss {version};
        string token;
        while (getline(ss, token, '.')) {
            val.push_back(stoi(token));
        }
        return val;
    }
    int compareVersion(string version1, string version2) {
        auto v1 = map_vector(version1);
        auto v2 = map_vector(version2);

        while (v1.size() < v2.size()) v1.push_back(0);
        while (v2.size() < v1.size()) v2.push_back(0);

        for (int i=0; i<v1.size(); i++) {
            auto a1 = v1[i];
            auto a2 = v2[i];
            if (a1 < a2) {
                return -1;
            } else if (a1 > a2) {
                return 1;
            }
        }
        return 0;
    }
};