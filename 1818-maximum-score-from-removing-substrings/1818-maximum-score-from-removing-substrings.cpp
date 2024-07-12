class Solution {
    int getPoints(string& s, string str, int points) {
        int totalPoints = 0, n = s.length();
        stack<char> st;
        for (auto ch : s) {
            if (st.empty())
                st.push(ch);
            else if (str[0] == st.top() && str[1] == ch) {
                totalPoints += points;
                st.pop();
            } else {
                st.push(ch);
            }
        }
        s = "";
        while (!st.empty()) {
            s.push_back(st.top()), st.pop();
        }
        reverse(s.begin(), s.end());
        return totalPoints;
    }

public:
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if (x < y)
            swap(s1, s2), swap(x, y);
        return getPoints(s, s1, x) + getPoints(s, s2, y);
    }
};