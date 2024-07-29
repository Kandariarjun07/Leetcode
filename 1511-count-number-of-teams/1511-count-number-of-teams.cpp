class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for (int j = 1; j < n - 1; j++) {
            int cnt_small_left = 0, cnt_small_right = 0;
            int cnt_large_left = 0, cnt_large_right = 0;
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j])
                    cnt_small_left++;
                if (rating[i] > rating[j])
                    cnt_large_left++;
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j])
                    cnt_small_right++;
                if (rating[k] > rating[j])
                    cnt_large_right++;
            }
            ans += (cnt_small_left * cnt_large_right) +
                   (cnt_large_left * cnt_small_right);
        }
        return ans;
    }
};