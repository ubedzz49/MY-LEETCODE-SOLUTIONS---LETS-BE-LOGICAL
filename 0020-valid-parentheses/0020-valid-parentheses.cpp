class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mpp;
        mpp[')']='(';
        mpp['}']='{';
        mpp[']']='[';
        stack<char> stk;
        for(auto it:s){
            if(it==')' || it==']' || it=='}'){
                if(stk.empty() || stk.top()!=mpp[it]) return false;
                else stk.pop();
            }
            else {stk.push(it); }
        }
        if(!stk.empty()) return false;
        return true;
    }
};