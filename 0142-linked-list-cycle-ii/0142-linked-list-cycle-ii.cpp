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
        unordered_map<ListNode*,int> mpp;
        ListNode* slow=head;
        while(slow){
            if(mpp[slow]!=0) return slow;
            mpp[slow]=1;
            slow=slow->next;
        }
        return nullptr;
    }
};