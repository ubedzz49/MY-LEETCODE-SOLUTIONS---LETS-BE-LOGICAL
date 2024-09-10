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
int gcd(int a,int b){
    for(int i=max(a,b);i>=1;i--){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
    return 1;
}

void addgcd(ListNode*& head){
    if(head->next==nullptr){
        return;
    }
    int a=gcd(head->val,head->next->val);
    ListNode* h=new ListNode;
    h->val=a;
    h->next=head->next;
    head->next=h;
    addgcd(head->next->next);
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        addgcd(head);
        return head;
    }
};