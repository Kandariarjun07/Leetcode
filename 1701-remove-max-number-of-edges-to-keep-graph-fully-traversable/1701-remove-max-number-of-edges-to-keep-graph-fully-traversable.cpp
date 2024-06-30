class DSU {
public:
    vector<int> Parent, Rank;

    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            Parent[i] = i;
    }

    int Find(int x) { return Parent[x] == x ? x : Parent[x] = Find(Parent[x]); }

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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsu_alice(n + 1), dsu_bob(n + 1);
        int removed_edges = 0, alice_edges = 0, bob_edges = 0;
        for (auto edge : edges) {
            if (edge[0] == 3) {
                if (dsu_alice.Union(edge[1], edge[2])) {
                    dsu_bob.Union(edge[1], edge[2]);
                    alice_edges++, bob_edges++;
                } else {
                    removed_edges++;
                }
            }
        }
        for (auto edge : edges) {
            if (edge[0] == 3)
                continue;
            if (edge[0] == 2) {
                if (dsu_bob.Union(edge[1], edge[2]))
                    bob_edges++;
                else
                    removed_edges++;
            } else {
                if (dsu_alice.Union(edge[1], edge[2]))
                    alice_edges++;
                else
                    removed_edges++;
            }
        }
        return alice_edges == n - 1 && bob_edges == n - 1 ? removed_edges : -1;
    }
};