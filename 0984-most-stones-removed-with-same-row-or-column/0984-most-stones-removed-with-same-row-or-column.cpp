class Solution {
public:
int find(unordered_map<int,int>& parent,int r){
    if(parent[r]==r){
        return r;
    }
    parent[r]=find(parent,parent[r]);
    return parent[r];
}
void join(unordered_map<int,int>& parent,unordered_map<int,long long>& size,int r1,int r2){
    r1=find(parent,r1);
    r2=find(parent,r2);
    if(size[r1]>size[r2]) swap(r1,r2);
    parent[r1]=r2;
    if(size[r2]>INT_MAX || size[r1]>INT_MAX){
        size[r2]=INT_MAX;
        return;
    }
    size[r2]+=size[r1];
}
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int> parent;
        unordered_map<int,long long> size;
        for(auto it:stones){
            parent[it[0]]=it[0];
            parent[-1-it[1]]=-1-it[1];
            size[it[0]]=1;
            size[-1-it[1]]=1;
        }
        for(auto it:stones){
            join(parent,size,(-1-it[1]),it[0]);
        }
        unordered_set<int> sett;
        for(auto it:stones){
            sett.insert(find(parent,it[0]));
        }
        return stones.size()- sett.size();
    }
};