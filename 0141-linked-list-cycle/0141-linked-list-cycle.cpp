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
    bool hasCycle(ListNode *head) {
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast){
            if(fast==slow) return 1;
            fast=fast->next;
            if(fast) fast=fast->next;
            slow=slow->next;
        }
        return 0;
    }
};