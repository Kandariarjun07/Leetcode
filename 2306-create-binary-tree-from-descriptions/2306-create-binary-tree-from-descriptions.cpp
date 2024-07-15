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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_map<int, bool> childMap;

        for (auto& desc : descriptions) {
            int parent = desc[0], child = desc[1], isLeft = desc[2];

            if (!nodeMap[parent]) {
                nodeMap[parent] = new TreeNode(parent);
            }

            if (!nodeMap[child]) {
                nodeMap[child] = new TreeNode(child);
            }

            if (isLeft) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }

            childMap[child] = true;
        }
        TreeNode* root = nullptr;
        for (auto& node : nodeMap) {
            if (!childMap[node.first]) {
                root = node.second;
                break;
            }
        }

        return root;
    }
};