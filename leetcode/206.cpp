/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        vector<int> stack;
        for(auto i = head; i != nullptr; i = i->next) {
            stack.push_back(i->val);
        }

        int top = stack.size() - 1;
        for(auto i = head; i != nullptr; i = i->next) {
            i->val = stack[top--];
        }

        return head;
    }
};
