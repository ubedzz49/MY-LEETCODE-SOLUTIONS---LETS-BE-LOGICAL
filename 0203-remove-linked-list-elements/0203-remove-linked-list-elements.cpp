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
    ListNode* removeElements(ListNode* head, int val) {
        while(head){
            if(head->val==val) head=head->next;
            else break;
        }
        ListNode* h=head;
        while(h && h->next){
            if(h->next->val==val){
                ListNode* temp=h->next->next;
                h->next=temp;
            }
             else h=h->next;
        }
        return head;
    }
};