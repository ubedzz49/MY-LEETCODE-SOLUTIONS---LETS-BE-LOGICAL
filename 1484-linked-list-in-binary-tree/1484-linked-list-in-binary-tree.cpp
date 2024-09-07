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
    bool ans=false;
    bool dfs(ListNode* head,TreeNode* root){
        if(root==NULL){
            if(head==NULL){
                return true;
            }
            return false;
        }
        if(head==NULL){
            return true;
        }
        if(root->val!=head->val){
            return false;
        }
        else{
            return dfs(head->next,root->left)||dfs(head->next,root->right);
        }
    }
    void check(ListNode* head,TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->val==head->val){
            ans=ans||dfs(head,root);
        }
        check(head,root->left);
        check(head,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        check(head,root);
        return ans;
    }
};