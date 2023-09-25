class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26);
        for(auto chr : t){
            freq[chr - 'a']++;
        }
        for(auto chr : s){
            freq[chr - 'a']--;
        }
        for(int diff = 0; diff < 26; diff++){
            if(freq[diff] != 0){
                return (char)(diff + 'a');
            }
        }
        return '*';
    }
};