class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& newint) {
        ints.push_back(newint);
        sort(ints.begin(),ints.end());
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


        // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        // for(auto it:ints) pq.push(it);
        // int st=pq.top()[0];
        // int end=pq.top()[1];
        // pq.pop();
        // vector<vector<int>> ans;
        // while(!pq.empty()){
        //     int s=pq.top()[0];
        //     int e=pq.top()[1];
        //     pq.pop();
        //     if(s<=end) end=max(e,end);
        //     else{
        //         ans.push_back({st,end});
        //         st=s;
        //         end=e;
        //     }
        // }
        ans.push_back({st,end});
        return ans;
    }
};