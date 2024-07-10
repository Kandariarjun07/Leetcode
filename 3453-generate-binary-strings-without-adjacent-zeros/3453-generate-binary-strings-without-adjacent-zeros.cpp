class Solution {
    void solve(int n, int idx, vector<string>& res, string str) {
        if (str.length() == n) {
            res.push_back(str);
            return;
        }
        solve(n, idx + 1, res, str + "1");
        if (str.empty() || str[idx - 1] == '1') {
            solve(n, idx + 1, res, str + "0");
        }
    }

public:
    vector<string> validStrings(int n) {
        vector<string> res;
        solve(n, 0, res, "");
        return res;
    }
};