/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* h=head;
        while(h!=nullptr){
            if(h->child){
                Node* nxt=h->next;
                h->next=h->child;
                h->next->prev=h;
                h->child=nullptr;
                Node* prev=h->next;
                while(prev->next!=nullptr) prev=prev->next;
                prev->next=nxt;
                if(nxt!=nullptr) nxt->prev=prev;
            }
            h=h->next;
        }
        return head;
    }
};