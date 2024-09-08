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
void ins(ListNode*& h,int e){
    if(h==nullptr){
        h=new ListNode;
        h->val=e;
        h->next=nullptr;
        return;
    }
    ins(h->next,e);
}
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> nums;
        while(head!=nullptr){
            nums.push_back(head->val);
            head=head->next;
        }
        int m=nums.size()/k;
        int r=nums.size()%k;
        int c=0;
        vector<ListNode*> ans;
        for(int i=0;i<k;i++){
           ListNode* v=nullptr;
            if(i<r){
                for(int j=0;j<=m;j++){
                    ins(v,nums[c]);
                    c++;
                }
            }else{
                for(int j=0;j<m;j++){
                    ins(v,nums[c]);
                    c++;
                }
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};