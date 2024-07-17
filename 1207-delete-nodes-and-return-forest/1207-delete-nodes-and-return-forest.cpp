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
    void helper(TreeNode* root, unordered_set<int>& to_delete_set,
                bool isParentConnected, vector<TreeNode*>& res) {
        if (root == nullptr)
            return;
        bool root_to_delete = to_delete_set.count(root->val) > 0;
        if (!root_to_delete && !isParentConnected) {
            res.push_back(root);
        }
        helper(root->left, to_delete_set, !root_to_delete, res);
        helper(root->right, to_delete_set, !root_to_delete, res);

        if (root->left != nullptr && to_delete_set.count(root->left->val) > 0) {
            root->left = nullptr;
        }
        if (root->right != nullptr &&
            to_delete_set.count(root->right->val) > 0) {
            root->right = nullptr;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        helper(root, to_delete_set, false, res);
        return res;
    }
};