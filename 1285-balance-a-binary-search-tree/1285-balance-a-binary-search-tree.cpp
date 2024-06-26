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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == NULL)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* buildTree(vector<int>& arr, int i, int j) {
        if (i > j) {
            return NULL;
        }
        int mid = i + (j - i) / 2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = buildTree(arr, i, mid - 1);
        node->right = buildTree(arr, mid + 1, j);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> elements;
        inorder(root, elements);
        
        return buildTree(elements, 0, elements.size() - 1);
    }
};