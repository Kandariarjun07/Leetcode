class Solution {
public:
    int solve(vector<vector<int>>& books, int i, int remWidth, int maxHt) {
        if (i >= n) return maxHt;

        if(dp[i][remWidth] != -1) return dp[i][remWidth];
        int bookW = books[i][0], bookH = books[i][1];

        int keep = INT_MAX, skip = INT_MAX;

        if(remWidth >= bookW) keep = solve(books , i+1, remWidth - bookW, max(maxHt,bookH));
        skip = maxHt + solve(books, i+1, WIDTH - bookW, bookH);

        return dp[i][remWidth] = min(keep,skip);
    }
    int WIDTH, n;
    int dp[1001][1001];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        n = books.size();
        WIDTH = shelfWidth;
        return solve(books, 0, shelfWidth, 0);
    }
};