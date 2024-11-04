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

    void travel(TreeNode* node, vector<int> &order) {
        if(!node) return;

        if(node->left) travel(node->left, order);
        order.push_back(node->val); 
        if(node->right) travel(node->right, order);

    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        this->travel(root, order);

        return order;
    }
};
