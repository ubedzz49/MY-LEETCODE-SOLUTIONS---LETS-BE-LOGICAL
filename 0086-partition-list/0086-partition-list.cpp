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
void ins(ListNode*& head,int ele){
    if(head==nullptr){
        ListNode* h=new ListNode;
        h->val=ele;
        h->next=nullptr;
        head=h;
        return;
    }
    ins(head->next,ele);
}

void insll(ListNode*& head,ListNode* h){
    if(head==nullptr){
        head=h;
        return;
    }
    insll(head->next,h);
}

    ListNode* partition(ListNode* head, int x) {
        ListNode* head2=nullptr;
        ListNode* head3=nullptr;
        while(head!=nullptr){
            if(head->val<x){
                ins(head2,head->val);
            }else{
                ins(head3,head->val);
            }
            head=head->next;
        }
        insll(head2,head3);
        return head2;
    }
};