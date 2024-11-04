class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
               
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                queue<int> q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            int c=color[n];
            if(c==0) {c=1;}
            else{c=0;}
            for(auto it:graph[n]){
                if(color[it]==-1){
                    color[it]=c;
                    q.push(it);
                }else{
                    if(color[it]!=c) return false;
                }
            }
        }
            }
        }
        for(auto it:color) cout<<it<<" ";
        return true;
    }
};