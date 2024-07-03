class Solution {
public:
    int minDifference(std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 4)
            return 0;

        int ans = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < 4; ++i) {
            int minVal = *min_element(arr.begin() + i, arr.end() - 3 + i);
            int maxVal = *max_element(arr.begin() + i, arr.end() - 3 + i);
            int diff = maxVal - minVal;
            ans = min(ans, diff);
        }

        return ans;
    }
};