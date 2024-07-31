class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;
        int min_deletions = 0;

        for (char c : s) {
            c == 'b' ? b_count++ : min_deletions = min(min_deletions + 1, b_count);
        }

        return min_deletions;
    }
};