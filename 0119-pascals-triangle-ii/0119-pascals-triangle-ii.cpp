class Solution {
public:
    vector<int> getRow(int num) {
        vector<int> v={1};
        for(int n=2;n<=num+1;n++){
            vector<int> p(n,0);
            for(int i=0;i<n-1;i++){
                p[i]+=v[i];
                p[i+1]+=v[i];
            }
            v=p;
        }
        return v;
    }
};