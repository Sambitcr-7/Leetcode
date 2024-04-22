class Solution {
public:
    unordered_set<string> deadends;
    unordered_set<string> visited;
    char inc(char c) {
        int num = c - '0';
        return (num + 1) % 10 + '0';
    }
    char dec(char c) {
        int num = c - '0';
        if (num == 0) {
            return '9';
        }
        return (num - 1) % 10 + '0';
    }
    int bfs(string target, string start) {
        this->visited.insert(start);
        queue<pair<string, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            string curStr = q.front().first;
            int cnt = q.front().second;
            if (curStr == target) {
                return cnt;
            }
            q.pop();
            for (int i = 0; i < 4; ++i) {
                char c = curStr[i];
                curStr[i] = inc(c);
                if (!visited.count(curStr) && !deadends.count(curStr)) {
                    visited.insert(curStr);
                    q.push({curStr, cnt+1});
                }
                curStr[i] = dec(c);
                if (!visited.count(curStr) && !deadends.count(curStr)) {
                    visited.insert(curStr);
                    q.push({curStr, cnt+1});
                }
                curStr[i] = c;
            }
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        for (string s : deadends) {
            this->deadends.insert(s);
        }
        if (this->deadends.count("0000")) {
            return -1;
        }
        return bfs(target, "0000");
    }
};