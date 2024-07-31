class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int b_cnt = 0, a_cnt = 0;
        vector<int> b_count(n, 0), a_count(n, 0);
        for (int i = 0; i < n; i++) {
            b_count[i] = b_cnt;
            if (s[i] == 'b')
                b_cnt++;
        }
        for (int i = n - 1; i >= 0; i--) {
            a_count[i] = a_cnt;
            if (s[i] == 'a')
                a_cnt++;
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, b_count[i] + a_count[i]);
        }
        return res != INT_MAX ? res : 0;
    }
};