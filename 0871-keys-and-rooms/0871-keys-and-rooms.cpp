class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int ans=rooms.size();
        unordered_map<int,bool> mpp;
        mpp[0]=1;
        ans--;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int r=q.front();
            q.pop();
            for(auto it:rooms[r]){
                if(!mpp[it]){
                    ans--;
                    if(ans==0) return true;
                    q.push(it);
                    mpp[it]=1;
                }
            }
        }
        if(ans==0) return true;
        return false;
    }
};