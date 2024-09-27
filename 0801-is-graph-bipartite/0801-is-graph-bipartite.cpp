class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        for(int k=0;k<graph.size();k++){
        vector<int> color(graph.size(),-1);
        queue<int> q;
        q.push(k);
        color[k]=0;
        while(!q.empty()){
            int c;
            int n=q.front();
            if(color[n]==0){
            c=1;
        }else{
            c=0;
        }
            
            q.pop();
            for(int i=0;i<graph[n].size();i++){
                if(color[graph[n][i]]==-1){
                    q.push(graph[n][i]);
                    color[graph[n][i]]=c;
                    continue;
                }
                else if(c!=color[graph[n][i]]){
                    return false;
                }
            }
        }
        }
        return true;
    }
};