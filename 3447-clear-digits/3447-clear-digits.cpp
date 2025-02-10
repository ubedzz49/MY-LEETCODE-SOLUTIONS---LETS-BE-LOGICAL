class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
        for(auto it:s){
            if(isdigit(it) && !stk.empty())stk.pop();
            else stk.push(it);
        }
        s="";
        while(!stk.empty()){
            s.push_back(stk.top());
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};