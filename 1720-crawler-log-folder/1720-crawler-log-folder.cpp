class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (auto& str : logs) {
            if (str == "../" || str == "./") {
                res = (res == 0 || str == "./") ? res : --res;
            } else
                res++;
        }
        return res;
    }
};