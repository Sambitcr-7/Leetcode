class Solution {
public:
    string minRemoveToMakeValid(string str) {
        for (int i = 0, count = 0; i < str.size(); i++) {
            char ch = str[i];
            if (ch == ')' && count == 0) str.erase(i, 1), i--;
            if (ch == ')' && count > 0) count--;
            if (ch == '(') count++;
        } 

        for (int i = str.size() - 1, count = 0; i >= 0; i--) {
            char ch = str[i];
            if (ch == '(' && count == 0) str.erase(i, 1);
            if (ch == '(' && count > 0) count--;
            if (ch == ')') count++;
        }      

        return str;
    }
};