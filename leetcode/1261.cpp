/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    map<int, int> values;

    FindElements(TreeNode* root) {
        root->val = 0;
        recoverBinaryTree(root);
    }

    void recoverBinaryTree(TreeNode* node) {
        values[node->val] = 1;
        if(node->left != nullptr) {
            node->left->val = node->val * 2 + 1;
            recoverBinaryTree(node->left);
        }

        if(node->right != nullptr) {
            node->right->val = node->val * 2 + 2;
            recoverBinaryTree(node->right);
        }
    }
    
    bool find(int target) {
        return values[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
