class Solution {
public:
    long long minimumSteps(string s) {
        int count=0;
        for(auto c:s){
            if(c=='0'){
                count++;
            }
        }
        queue<int> q;
        for(int i=0;i<count;i++){
            if(s[i]=='1'){
                q.push(i);
            }
        }
        long long swapsreq=0;
        for(int i=count;i<s.size();i++){
            if(s[i]=='0'){
                swapsreq+=(i-q.front());
                q.pop();
            }
        }
        return swapsreq;
    }
};