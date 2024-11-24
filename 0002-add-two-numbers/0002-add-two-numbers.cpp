
class Solution {
public:
void insert(ListNode*& head,int ele){
    if(head==nullptr){
        head=new ListNode;
        head->val=ele;
        head->next=nullptr;
        return;
    }
    insert(head->next,ele);
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1,nums2;
        while(l1!=nullptr){
            nums1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            nums2.push_back(l2->val);
            l2=l2->next;
        }
        if(nums1.size()<nums2.size()) swap(nums1,nums2);
        int c=0;
        for(auto it:nums2){
            nums1[c]+=it;
            c++;
        } 
        c=0;
        for(int i=0;i<nums1.size();i++){
            nums1[i]+=c;
            c=nums1[i]/10;
            nums1[i]%=10;
        }
        if(c!=0) nums1.push_back(c);
        ListNode* head=nullptr;
        for(auto it:nums1)insert(head,it);
        return head;
    }
};