class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<char> sta;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'){
                sta.push('B');
            }else if(s[i]=='C'){
                sta.push('D');
            }else{
                if(sta.empty()){
                    continue;
                }
                if(s[i]==sta.top()){
                    sta.pop();
                    n-=2;
                }else{
                    stack<char> ss;
                    sta=ss;
                }
            }
        }
        return n;
    }
};