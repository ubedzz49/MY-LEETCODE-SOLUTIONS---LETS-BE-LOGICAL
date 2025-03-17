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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        unordered_map<ListNode*,bool> mpp;
        while(a){
            mpp[a]=1;
            a=a->next;
        }
        ListNode* b=headB;
        while(b){
            if(mpp[b]==1) return b;
            b=b->next;
        }
        return nullptr;
    }
};