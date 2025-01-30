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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void make(vector<int>& nums,int i,int j,TreeNode*& root){
    if(i>j) return;
    int ind=(i+j)/2;
    TreeNode* newnode=new TreeNode;
    newnode->val=nums[ind];
    newnode->left=nullptr;
    newnode->right=nullptr;
    root=newnode;
    make(nums,i,ind-1,root->left);
    make(nums,ind+1,j,root->right);
}
    TreeNode* fromvec(vector<int>& nums) {
        TreeNode* ans=nullptr;
        make(nums,0,nums.size()-1,ans);
        return ans;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head!=nullptr){
            nums.push_back(head->val);
            head=head->next;
        }
        return fromvec(nums);
    }
};