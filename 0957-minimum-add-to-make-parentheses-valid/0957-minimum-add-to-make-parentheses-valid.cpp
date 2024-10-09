class Solution {
public:
    int minAddToMakeValid(string s) {
        int c=0;
        stack<char> st1;
        for(auto i:s){
            if(i=='('){
                st1.push(i);
            }else{
                if(st1.empty()){
                    c++;
                }
                else{
                    st1.pop();
                }
            }
        }
        return c+st1.size();
    }
};