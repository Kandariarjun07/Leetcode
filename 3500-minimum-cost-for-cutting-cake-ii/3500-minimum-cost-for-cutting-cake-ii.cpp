class Solution {
    #define ll long long
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut,
                          vector<int>& verticalCut) {
        ll horizontalSections = 1, verticalSections = 1, i = 0, j = 0;
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        ll ans = 0;
        while (i < m - 1 && j < n - 1) {
            if (horizontalCut[i] >= verticalCut[j]) {
                ans += horizontalCut[i++] * verticalSections;
                horizontalSections++;
            } else {
                ans += verticalCut[j++] * horizontalSections;
                verticalSections++;
            }
        }
        while (i < m - 1) {
            ans += horizontalCut[i++] * verticalSections;
            horizontalSections++;
        }
        while (j < n - 1) {
            ans += verticalCut[j++] * horizontalSections;
            verticalSections++;
        }
        return ans;
    }
};