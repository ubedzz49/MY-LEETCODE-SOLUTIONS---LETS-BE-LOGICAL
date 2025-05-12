class Solution {
public:
pair<int,int> opf1(int x,int y,pair<int,int> p){
    return make_pair(x,p.second);
}
pair<int,int> opf2(int x,int y,pair<int,int> p){
    return make_pair(p.first,y);
}
pair<int,int> ops1(int x,int y,pair<int,int> p){
    return make_pair(0,p.second);
}
pair<int,int> ops2(int x,int y,pair<int,int> p){
    return make_pair(p.first,0);
}
pair<int,int> opt1(int x,int y,pair<int,int> p){
    if(p.second>= (x-p.first)) return make_pair(x, p.second - (x-p.first));
    else return make_pair(p.second+p.first,0);
}
pair<int,int> opt2(int x,int y,pair<int,int> p){
    if(p.first>= (y-p.second)) return make_pair(p.first - (y-p.second), y);
    else return make_pair(0,p.second+p.first);
}
    bool canMeasureWater(int x, int y, int target) {
        queue<pair<int,int>> q;
        map<pair<int,int>,bool> mpp;
        mpp[make_pair(0,0)]=1;
        q.push(make_pair(0,0));
        while(!q.empty()){
            if(q.front().first+q.front().second==target) return true;
            pair<int,int> p=q.front();
            q.pop();
            pair<int,int> np=opf1(x,y,p);
            if(!mpp[np]){
                mpp[np]=1;
                q.push(np);
            }
            np=opf2(x,y,p);
            if(!mpp[np]){
                mpp[np]=1;
                q.push(np);
            }
             np=ops1(x,y,p);
            if(!mpp[np]){
                mpp[np]=1;
                q.push(np);
            }
             np=ops2(x,y,p);
            if(!mpp[np]){
                mpp[np]=1;
                q.push(np);
            }
              np=opt1(x,y,p);
            if(!mpp[np]){
                mpp[np]=1;
                q.push(np);
            }
             np=opt2(x,y,p);
            if(!mpp[np]){
                mpp[np]=1;
                q.push(np);
            }
        }
        return false;
    }
};