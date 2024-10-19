class Solution {
public:
    void make(int v, vector<int>& parent) { 
        parent[v] = v;
         }

    int find(int v,vector<int>& parent){
        if(parent[v]==v){
            return v;
        }
        parent[v]=find(parent[v],parent);
        return parent[v];
    }

    void join(int u,int v,vector<int>& parent,vector<int>& size){
        u=find(u,parent);
        v=find(v,parent);
        if(size[u]>size[v]){
            swap(u,v);
        }
        parent[u]=v;
        size[v]+=size[u];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
            vector<int> parent(1001,-1);
            vector<int> size(1001,1);
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int d = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);
                pq.push({d, i, j});
                make(i,parent);
                make(j,parent);
            }
        }
        int ans=0;
        int n=0;
        while(n<points.size()-1){
            vector<int> it=pq.top();
            pq.pop();
            if(find(it[1],parent)==find(it[2],parent)){
                continue;
            }
            ans+=it[0];
            join(it[1],it[2],parent,size);
            n++;
        }
        return ans;
    }
};