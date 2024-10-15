/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        while (1) {
            if(head==nullptr){
                return false;
            }
            cout << head->val<<endl;
            if (head->val == INT_MIN) {
                return true;
            }
            head->val = INT_MIN;
            ListNode* head2 = head->next;
            head=head2;
        }
        return false;
    }
};