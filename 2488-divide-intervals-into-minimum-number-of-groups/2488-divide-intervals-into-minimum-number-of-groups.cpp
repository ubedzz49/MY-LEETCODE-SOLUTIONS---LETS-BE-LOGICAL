class Solution {
public:
    int minGroups(vector<vector<int>>& intr) {
        int ans=0;
        vector<int> s,e;
        for(auto i:intr){
            s.push_back(i[0]);
            e.push_back(i[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int k=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>e[k]){
                k++;
            }else{
                count++;
            }
        }
        return count;
    }
};