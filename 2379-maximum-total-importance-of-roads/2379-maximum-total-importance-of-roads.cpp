class Solution {
    typedef pair<int, int> p;

public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        for (auto path : roads) {
            indegree[path[0]]++;
            indegree[path[1]]++;
        }
        priority_queue<p> pq;
        for (int i = 0; i < n; i++) {
            pq.push({indegree[i], i});
        }
        while (!pq.empty()) {
            auto pr = pq.top();
            pq.pop();
            indegree[pr.second] = n--;
        }
        long long ans = 0;
        for (auto edge : roads) {
            int u = edge[0], v = edge[1];
            ans += indegree[u] + indegree[v];
        }
        return ans;
    }
};