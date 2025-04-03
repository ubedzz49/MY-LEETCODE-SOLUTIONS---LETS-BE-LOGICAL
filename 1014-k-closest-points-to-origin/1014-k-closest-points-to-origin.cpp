class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>> pq;
        for(int i=0;i<points.size();i++){
            pq.push(make_pair( (sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1])) ,i));
            //cout<<(sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]))<<" ";
            }
            vector<vector<int>> ans;
            while(k>0){
                k--;
                //cout<<pq.top().second<<endl;
                ans.push_back(points[pq.top().second]);
                pq.pop();
            }
        return ans;
    }
};