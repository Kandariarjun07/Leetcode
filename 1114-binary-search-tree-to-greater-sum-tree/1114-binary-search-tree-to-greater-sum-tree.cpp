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
    void reverseInorder(TreeNode* root, int& sum) {
        if (root == NULL)
            return;
        reverseInorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left, sum);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
        /*
        vector<int> inorder;
        getInorder(root, inorder);

        int n = inorder.size();
        for (int i = n - 2; i >= 0; i--) {
            inorder[i] = inorder[i] + inorder[i + 1];
        }

        int index = 0;
        setInorder(root, inorder, index);
        return root;
        */
    }
};