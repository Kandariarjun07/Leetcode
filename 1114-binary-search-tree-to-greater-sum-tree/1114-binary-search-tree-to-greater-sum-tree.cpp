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
    void getInorder(TreeNode* root, vector<int>& inorder) {
        if (root == NULL)
            return;
        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }

    void setInorder(TreeNode* root, vector<int>& inorder, int& i) {
        if (root == NULL)
            return;
        setInorder(root->left, inorder, i);
        root->val = inorder[i++];
        setInorder(root->right, inorder, i);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);

        int n = inorder.size();
        for (int i = n - 2; i >= 0; i--) {
            inorder[i] = inorder[i] + inorder[i + 1];
        }

        int index = 0;
        setInorder(root, inorder, index);
        return root;
    }
};