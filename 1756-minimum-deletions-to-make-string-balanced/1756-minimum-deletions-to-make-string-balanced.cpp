class Solution {
public:
    int minimumDeletions(string s) {
        int a_count = 0, b_count = 0;
        int res = INT_MAX;
        for (auto c : s)
            if (c == 'a')
                a_count++;
        for (char c : s) {
            if (c == 'a')
                a_count--;
            res = min(res, a_count + b_count);
            if (c == 'b')
                b_count++;
        }
        return res;
    }
};