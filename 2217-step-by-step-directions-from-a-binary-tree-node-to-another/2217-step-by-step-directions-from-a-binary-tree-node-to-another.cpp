/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root, int startValue, int destValue, string& rootToStart,
             string& rootToEnd, string& pathString) {
        if (root == NULL) return;

        if (root->val == startValue) rootToStart = pathString;
        if (root->val == destValue) rootToEnd = pathString;

        pathString.push_back('L');
        dfs(root->left, startValue, destValue, rootToStart, rootToEnd, pathString);
        pathString.pop_back();

        pathString.push_back('R');
        dfs(root->right, startValue, destValue, rootToStart, rootToEnd, pathString);
        pathString.pop_back();
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToStart, rootToEnd, pathString = "";
        dfs(root, startValue, destValue, rootToStart, rootToEnd, pathString);
        int commonLen = 0;
        int i = 0;
        while (i < rootToStart.length() && i < rootToEnd.length()) {
            if (rootToStart[i] == rootToEnd[i]) commonLen++, i++;
            else break;
        }
        rootToStart = rootToStart.substr(commonLen, rootToStart.length() - commonLen);
        rootToEnd = rootToEnd.substr(commonLen, rootToEnd.length() - commonLen);

        for (auto& ch : rootToStart) ch = 'U';
        return rootToStart + rootToEnd;
    }
};