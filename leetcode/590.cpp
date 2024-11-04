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

        if(node->children.size()) {
            for (Node* child : node->children)
                travel(child, order);
        }

        order.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> order;
        travel(root, order);

        return order;
    }
};
