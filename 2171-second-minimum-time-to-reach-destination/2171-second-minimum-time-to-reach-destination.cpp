class Solution {
public:
#define P pair<int, int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj(n + 1);
        for (auto e : edges) {
            int v = e[0], w = e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
        }
        vector<int> d1(n + 1, INT_MAX), d2(n + 1, INT_MAX);
        queue<P> que;
        que.push({1, 1});
        d1[1] = 0;
        while (!que.empty()) {
            auto [node, freq] = que.front();
            que.pop();
            int timePassed = (freq == 1) ? d1[node] : d2[node];
            int div = timePassed / change;
            if (div % 2 == 1) {
                timePassed = (div + 1) * change;
            }
            if (node == n && d2[n] != INT_MAX)
                return d2[n];
            for (auto& nbr : adj[node]) {
                if (d1[nbr] == INT_MAX) {
                    d1[nbr] = timePassed + time;
                    que.push({nbr, 1});
                } else if (d2[nbr] == INT_MAX && timePassed + time != d1[nbr]) {
                    d2[nbr] = timePassed + time;
                    que.push({nbr, 2});
                }
            }
        }
        return -1;
    }
};