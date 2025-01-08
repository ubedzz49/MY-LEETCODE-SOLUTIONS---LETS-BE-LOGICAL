class Solution {
public:
 int area(vector<int>& heights) {
        stack<pair<int,int>> s;
        s.push(make_pair(heights[0],0));
        int ans=0;
        vector<vector<int>> near(heights.size());
        for(int i=1;i<heights.size();i++){
            while(!(s.empty() || heights[i]>s.top().first)){
                s.pop();
            }
            if(s.empty()){
                near[i].push_back(-1);
            }
            else near[i].push_back(s.top().second);
            s.push(make_pair(heights[i],i));
        }
        while (!s.empty()) {
    s.pop();
}
       
        near[0].push_back(-1);
        reverse(heights.begin(),heights.end());
        reverse(near.begin(),near.end()); s.push(make_pair(heights[0],0));
        for(int i=1;i<heights.size();i++){
            while(!(s.empty() || heights[i]>s.top().first)){
                s.pop();
            }
            if(s.empty()){
                near[i].push_back(heights.size());
            }
            else near[i].push_back(heights.size()-1-s.top().second);
            s.push(make_pair(heights[i],i));
        }
        near[0].push_back(heights.size());

        reverse(heights.begin(),heights.end());
        reverse(near.begin(),near.end());

        for(auto it:near) cout<<it[0]<<" "<<it[1]<<endl;

        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(near[i][1]-near[i][0]-1));
        };
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size(),0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') dp[j]++;
                else dp[j]=0;
            }
            ans=max(ans,area(dp));
        }
        return ans;
    }
};