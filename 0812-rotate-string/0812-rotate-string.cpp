class Solution {
public:
    bool rotateString(string s, string goal) {
       s=s+s;
       if(s.size()!=goal.size()*2){
        return false;
       }
       for(int i=0;i<s.size()-goal.size();i++){
        if(s.substr(i,goal.size())==goal){
            return true;
        }
       }
       return false;
    }
};