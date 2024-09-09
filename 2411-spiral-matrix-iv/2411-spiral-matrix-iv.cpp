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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> v(n,-1);
        vector<vector<int>> ans(m,v);
        int is=0;
        int ie=m-1;
        int js=0;
        int je=n-1;
        while(head!=nullptr){
            if(!(js<je)){
                for(int i=is;i<=ie;i++){
                if(head==nullptr){
                    return ans;
                }
                ans[i][je]=head->val;
                head=head->next;
            }
                return ans;
            }
            for(int j=js;j<=je;j++){
                if(head==nullptr){
                    return ans;
                }
                ans[is][j]=head->val;
                head=head->next;
            }
            if(!(is<ie)){
                return ans;
            }
            for(int i=is+1;i<ie;i++){
                if(head==nullptr){
                    return ans;
                }
                ans[i][je]=head->val;
                head=head->next;
            }
            for(int j=je;j>=js;j--){
                if(head==nullptr){
                    return ans;
                }
                ans[ie][j]=head->val;
                head=head->next;
            }
            for(int i=ie-1;i>is;i--){
                if(head==nullptr){
                    return ans;
                }
                ans[i][js]=head->val;
                head=head->next;
            }
            is++;
            ie--;
            js++;
            je--;
        }
        return ans;
    }
};