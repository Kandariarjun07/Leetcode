class Solution {
private:
    int atMost(vector<int>& nums, int goal) {
        int i = 0, j = 0, ans = 0, sum = 0, n = nums.size();
        while (j < n) {
            sum += nums[j];
            while (sum > goal && i <= j) {
                sum -= nums[i];
                i++;
            }
            // j - i + 1 adds all the possible number of new subarray
            ans += j - i + 1;
            j++;
        }
        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // here two pointer works because we dont have negative numbers and increment of j would never decrese the sum
        // (sum = k) ---> (sum <= k) - (sum < k)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};