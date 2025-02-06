class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& newint) {
           int c=0;
            for(int i=0;i<ints.size();i++){
                if(ints[i][0]<newint[0]) c++;
            }
            ints.insert(ints.begin()+c,newint);
        int st=ints[0][0];
        int end=ints[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<ints.size();i++){
            int s=ints[i][0];
            int e=ints[i][1];
            if(s<=end) end=max(e,end);
            else{
                ans.push_back({st,end});
                st=s;
                end=e;
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};