/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void travel(Node* node, vector<int> &order) {
        if(!node) return;
        order.push_back(node->val);
        for(Node* child : node->children) {
            travel(child, order);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> order;
        travel(root, order);

        return order;
    }
};
