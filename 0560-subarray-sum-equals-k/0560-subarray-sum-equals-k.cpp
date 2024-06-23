class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, prefixSum = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        for (auto it : nums) {
            prefixSum += it;
            ans += freq[prefixSum - k];
            freq[prefixSum]++;
        }
        return ans;
    }
};