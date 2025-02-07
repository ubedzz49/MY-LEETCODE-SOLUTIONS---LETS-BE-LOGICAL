class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int c=0;
        vector<int> ans;
        unordered_map<int,int> mpp;
        unordered_map<int,int> iscol;
        for(auto it:queries){
            int x=it[0];
            int y=it[1];
            if(iscol[x]==0){
                iscol[x]=y;
                if(mpp[y]==0){
                    c++;
                }
                mpp[y]++;
                ans.push_back(c);
            }
            else{
                mpp[iscol[x]]--;
                if(mpp[iscol[x]]==0) c--;
                iscol[x]=y;
                if(mpp[y]==0){
                    c++;
                }
                mpp[y]++;
                ans.push_back(c);
            }
        }
        return ans;
    }
};