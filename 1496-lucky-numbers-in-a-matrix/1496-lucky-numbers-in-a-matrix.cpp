class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size(), cols = matrix[0].size();

        vector<int> rowMin(rows);
        for (int i = 0; i < rows; i++) {
            rowMin[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }

        vector<int> colMax(cols, INT_MIN);
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                colMax[i] = max(matrix[j][i], colMax[i]);
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};