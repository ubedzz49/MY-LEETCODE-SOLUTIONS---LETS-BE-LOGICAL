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
void ins(ListNode*& head,int v){
    if(head==nullptr){
        head=new ListNode;
        head->val=v;
        head->next=nullptr;
        return;
    }
    ins(head->next,v);
}
    ListNode* deleteDuplicates(ListNode* head) {

            ListNode* ans=nullptr;
            if(head==nullptr){
                return nullptr;
            }
            vector<int> nums;
            while(head!=nullptr){
               nums.push_back(head->val);
                head=head->next;
            }
            int c=1;
            for(int i=1;i<nums.size();i++){
                if(nums[i]!=nums[i-1]){
                    if(c==1){
                        ins(ans,nums[i-1]);
                    }
                    c=1;
                }else{
                    c++;
                }
            }
            if(c==1){
                ins(ans,nums[nums.size()-1]);
            }
            return ans;
    }
};