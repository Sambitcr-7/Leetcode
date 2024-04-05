class Solution {
public:
    string makeGood(string s) {
        int n = s.size();

        stack<char> st;

        for(int i = 0; i < n; i++){
            if(!st.empty() and abs(st.top()-s[i]) == 32){
                st.pop();
            } else st.push(s[i]);
        }

        string ans = "";

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};