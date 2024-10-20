class Solution {
public:
int find(vector<int>& parent,int v){
    if(parent[v]==v) return v;
    parent[v]=find(parent,parent[v]);
    return parent[v];
}
void join(vector<int>& parent,int v,int u,vector<int>& size){
    u=find(parent,u);
    v=find(parent,v);
    if(size[u]>size[v]) swap(u,v);
    parent[u]=v;
    size[v]+=size[u];
}
    int makeConnected(int n, vector<vector<int>>& it) {
        vector<int> parent(n);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        vector<int> size(n,1);
        int count=0;
        for(auto c:it){
           if(find(parent,c[0])==find(parent,c[1])){
            count++;
            continue;
           }
           join(parent,c[0],c[1],size); 
        }
        int cc=0;
        for(int i=1;i<n;i++){
            if(find(parent,i-1)==find(parent,i)) continue;
            cc++;
            join(parent,i-1,i,size);
        }
        if(cc>count) return -1;
        return cc;
    }
};