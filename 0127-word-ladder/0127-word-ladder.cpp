class Solution {
public:
    int ladderLength(string st, string tgt, vector<string>& wl) {
        vector<vector<string>> ans;
        unordered_set<string> sett(wl.begin(),wl.end());
        queue<pair<string,vector<string>>> q;
        vector<string> hhh;
        hhh.push_back(st);
        q.push(make_pair(st,hhh));
        sett.erase(st);
        int limit=INT_MAX;
        int cl=1;
        vector<string> usedonlevel;
        while(!q.empty()){
            string s=q.front().first;
            vector<string> v=q.front().second;
            
            if(v.size()>limit){
                break;
            }
            
            if(v.size()+1>cl){
                cl=v.size()+1;
                for(auto it:usedonlevel) sett.erase(it);
                vector<string> u;
                usedonlevel=u;
            }
            q.pop();
            if(v.size()>limit){
                break;
            }
            for(int i=0;i<s.size();i++){
                string s1=s;
                for(int j=0;j<26;j++){
                    int nn='a'+j;
                    s1[i]=nn;
                    if(sett.count(s1)>0){
                        usedonlevel.push_back(s1);
                        v.push_back(s1);
                        if(s1==tgt){
                            ans.push_back(v);
                            return v.size();
                            limit=v.size();
                        }else{
                            q.push(make_pair(s1,v));
                        }
                        v.pop_back();
                    }
                }
            }
        }
        return 0;
    }
};