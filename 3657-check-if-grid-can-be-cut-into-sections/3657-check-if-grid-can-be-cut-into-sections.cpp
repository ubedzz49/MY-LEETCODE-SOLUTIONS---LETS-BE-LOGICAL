class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hori;
        vector<vector<int>> vert;
        vector<vector<int>> hmap;
        vector<vector<int>> vmap;
        for(auto coor:rectangles){
            int sx = coor[0];
            int ex = coor[2];
            int sy = coor[1];
            int ey = coor[3];
            hmap.push_back({sx, ex});
            vmap.push_back({sy, ey});
        }
        sort(hmap.begin(), hmap.end());
        sort(vmap.begin(), vmap.end());

        for(auto h:hmap){
            if(hori.empty()||hori.back()[1]<=h[0]) hori.push_back(h);
            else hori.back()[1]=max(hori.back()[1], h[1]);
        }
        if(hori.size()>2) return true;
        for(auto v:vmap){
            if(vert.empty()||vert.back()[1]<=v[0]) vert.push_back(v);
            else vert.back()[1]=max(vert.back()[1], v[1]);
        }
        if(vert.size()>2) return true;
        return false;
    }
};