class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        bool b=1;
        vector<int> ans;
        bool c=0;
        for(auto it:grid){
            if(c)reverse(it.begin(),it.end());
            c=!c;
            for(auto jt:it){
                if(b==1) ans.push_back(jt);
                b=!b;
            }
        }
        return ans;
    }
};