class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> indegree;
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            indegree[u]++;
            indegree[v]++;
        }
        int ans = INT_MIN;
        for(auto [ele,in] : indegree){
            if(ans == INT_MIN){
                ans = ele;
            }
            else{
                if(indegree[ans] < in){
                    ans = ele;
                }
            }
        }
        return ans;

    }
};