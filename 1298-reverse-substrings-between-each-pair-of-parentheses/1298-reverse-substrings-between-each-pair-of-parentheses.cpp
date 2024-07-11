class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> oppIdx(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                oppIdx[i] = st.top();
                oppIdx[st.top()] = i;
                st.pop();
            }
        }
        string ans = "";
        int direction = 1;
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = oppIdx[i];
                direction *= -1;
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};