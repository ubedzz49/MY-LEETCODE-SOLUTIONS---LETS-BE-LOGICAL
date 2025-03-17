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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr) return nullptr;
        ListNode* fast=head->next;
        ListNode* slow=head;
        if(fast) fast=fast->next;
        if(fast)  fast=fast->next;
        while(fast){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        if(slow->next){
            ListNode* t=slow->next;
            if(t) t=t->next;
            slow->next=t;
        }
        return head;
        return nullptr;
    }
};