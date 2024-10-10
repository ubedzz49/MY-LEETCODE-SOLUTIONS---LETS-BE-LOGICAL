class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        vector<int> md1(heights[0].size(),INT_MAX);
        vector<vector<int>> md(heights.size(),md1);
        md[0][0]=0;
        vector<int> drow={-1,+1,0,0};
        vector<int> dcol={0,0,-1,+1};
        while(!pq.empty()){
            int r=pq.top()[1];
            int c=pq.top()[2];
            int diff=pq.top()[0];
            pq.pop();
            for(int i=0;i<4;i++){
                int dr=r+drow[i];
                int dc=c+dcol[i];
                if(dr<0 || dc<0 || dr>=heights.size() || dc>=heights[0].size()){
                    continue;
                }
                int newd=max(diff,abs(heights[dr][dc]-heights[r][c]));
                if(newd<md[dr][dc]){
                    md[dr][dc]=newd;
                    pq.push({newd,dr,dc});
                }
            }
        }
        return md[md.size()-1][md[0].size()-1];
    }
};