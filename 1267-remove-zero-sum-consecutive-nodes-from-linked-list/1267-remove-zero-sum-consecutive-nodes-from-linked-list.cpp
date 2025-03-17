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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        unordered_map<int,ListNode*> mpp;
        int sm = 0;
        ListNode* h = &dummy;
        while (h) {
            sm+=h->val;
            if (mpp.count(sm)) {
                ListNode* prev=mpp[sm];
                ListNode* temp=prev->next;
                int sum = sm;
                while (temp != h) {
                    sum+= temp->val;
                    mpp.erase(sum);
                    temp = temp->next;
                }
                
                prev->next=h->next; 
            } else {
                mpp[sm]=h;
            }
            h= h->next;}
        return dummy.next;
    }
};
