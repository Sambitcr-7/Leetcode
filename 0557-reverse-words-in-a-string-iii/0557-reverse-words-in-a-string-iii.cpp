class Solution {
public:
    string reverseWords(string s);
};
/***********************************************************/
string Solution::reverseWords(string s) {
    stringstream ss(s);
    string word, ans;
    char del = ' ';
    int i = 0;
    while (!ss.eof()) {
        getline(ss, word, del);
        reverse(word.begin(), word.end());
        if (i == 0) {
            ans+=word;
        } else {
            ans+=del+word;
        }
        ++i;
    }
    return ans;
}