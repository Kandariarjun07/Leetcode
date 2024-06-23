class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0, ans = INT_MIN, n = nums.size();
        deque<pair<int, int>> minDq, maxDq;
        while (j < n) {
            while (!minDq.empty() && minDq.back().first > nums[j])  minDq.pop_back();
            while (!maxDq.empty() && maxDq.back().first < nums[j])  maxDq.pop_back();

            minDq.push_back({nums[j], j});
            maxDq.push_back({nums[j], j});

            int diff = maxDq.front().first - minDq.front().first;

            while (i <= j && diff > limit) {
                i = min(maxDq.front().second, minDq.front().second) + 1;

                while (!minDq.empty() && minDq.front().second < i)  minDq.pop_front();
                while (!maxDq.empty() && maxDq.front().second < i)  maxDq.pop_front();

                diff = maxDq.front().first - minDq.front().first;
            }
            
            ans = max(ans, j - i + 1);
            j++;
        }

        /*
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        while (j < n) {
            minHeap.push({nums[j], j});
            maxHeap.push({nums[j], j});
            int diff = maxHeap.top().first - minHeap.top().first;
            while (i <= j && diff > limit) {
                i = min(maxHeap.top().second, minHeap.top().second) + 1;
                while (minHeap.top().second < i)
                    minHeap.pop();
                while (maxHeap.top().second < i)
                    maxHeap.pop();
                diff = maxHeap.top().first - minHeap.top().first;
            }
            ans = max(ans, j - i + 1);
            j++;
        }

        multiset<int> mset;
        while (j < n) {
            mset.insert(nums[j]);
            int diff = *mset.rbegin() - *mset.begin();
            while (i <= j && diff > limit) {
                mset.erase(mset.find(nums[i]));
                diff = *mset.rbegin() - *mset.begin();
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        */
        return ans;
    }
};