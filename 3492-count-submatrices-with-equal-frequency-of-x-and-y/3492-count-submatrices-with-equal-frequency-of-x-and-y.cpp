class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<pair<int, int>>> pref(n,
                                            vector<pair<int, int>>(m, {0, 0}));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j] = (grid[i][j] == 'X')
                                 ? make_pair(1, 0)
                                 : (grid[i][j] == 'Y' ? make_pair(0, 1)
                                                      : make_pair(0, 0));
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                pref[i][j].first += pref[i][j - 1].first;
                pref[i][j].second += pref[i][j - 1].second;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j].first += pref[i - 1][j].first;
                pref[i][j].second += pref[i - 1][j].second;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pref[i][j].first == pref[i][j].second && pref[i][j].first != 0)
                    res++;
            }
        }
        return res;
    }
};