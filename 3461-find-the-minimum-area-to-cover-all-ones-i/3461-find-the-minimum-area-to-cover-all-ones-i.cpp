class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row_min = INT_MAX, row_max = INT_MIN;
        int col_min = INT_MAX , col_max = INT_MIN;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    row_min = min(i, row_min);
                    col_min = min(j, col_min);
                    row_max = max(i, row_max);
                    col_max = max(j, col_max);
                }
            }
        }
        int breadth = col_max - col_min + 1;
        int len = row_max - row_min + 1;
        return len * breadth;
    }
};