class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_sum = 0, double_sum = 0;
        for (auto it : nums) {
            if (it / 10 == 0)
                single_sum += it;
            else
                double_sum += it;
        }
        return single_sum != double_sum;
    }
};