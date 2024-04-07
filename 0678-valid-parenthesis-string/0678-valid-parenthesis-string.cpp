class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack;
        stack<int> asteriskStack;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openStack.push(i);
            } else if (s[i] == '*') {
                asteriskStack.push(i);
            } else {
                if (!openStack.empty()) {
                    openStack.pop();
                } else if (!asteriskStack.empty()) {
                    asteriskStack.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openStack.empty() && !asteriskStack.empty()) {
            if (openStack.top() > asteriskStack.top()) {
                return false;
            }
            openStack.pop();
            asteriskStack.pop();
        }

        return openStack.empty();
    }
};