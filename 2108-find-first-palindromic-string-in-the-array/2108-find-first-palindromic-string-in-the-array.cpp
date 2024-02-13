class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto itr : words){
            string palin = itr;
            reverse(palin.begin(),palin.end());
            if(palin==itr){
                return palin;
            }
        }
        return "";
    }
};