class Solution {
public:
    bool canConstruct(string r, string m) {
        sort(r.begin(),r.end());
        sort(m.begin(),m.end());
        int c=0;
        for(int i=0;i<m.size();i++){
            if(r[c]==m[i]){
                c++;
            }
        }
        if(c==r.size()){
            return 1;
        }
        return 0;
    }
};