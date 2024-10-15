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
    ListNode *detectCycle(ListNode *head) {
        int c=0;
        vector<ListNode*> v;
        while(head!=nullptr){
            if(head->val>100000){
                int n=INT_MAX;
                n-=(head->val);
                return v[n];
            }
            v.push_back(head);
            head->val=INT_MAX-c;
            head=head->next;
            c++;
        }
        return head;
    }
};