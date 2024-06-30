class DSU {
public:
    vector<int> Parent, Rank;
    
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) 
            Parent[i] = i;
    }
    
    int Find(int x) {
        return Parent[x] == x ? x : Parent[x] = Find(Parent[x]);
    }
    
    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            if (Rank[xset] < Rank[yset])
                Parent[xset] = yset;
            else if (Rank[xset] > Rank[yset])
                Parent[yset] = xset;
            else {
                Parent[yset] = xset;
                Rank[xset]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU ds(n);
        for(int i = 0; i<queries.size(); i++) queries[i].push_back(i);
        sort(edgeList.begin(),edgeList.end(),[&](auto a,auto b){
            return a[2] < b[2];
        });
        sort(queries.begin(),queries.end(),[&](auto a, auto b){
            return a[2] < b[2];
        });
        int i = 0;
        vector<bool> res(queries.size(),false);
        for(auto q : queries){
            while(i < edgeList.size() && edgeList[i][2] < q[2]){
                ds.Union(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            if(ds.Find(q[0]) == ds.Find(q[1])){
                res[q[3]] = true;
            }
        }
        return res;
    }
};