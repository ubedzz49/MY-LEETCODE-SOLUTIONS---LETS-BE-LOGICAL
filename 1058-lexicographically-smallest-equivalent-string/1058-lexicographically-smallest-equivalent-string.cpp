class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<int>> v(26);
        int n = s1.length();
        for(int i=0;i<n;i++){
            int a = s1[i]-'a';
            int b = s2[i]-'a';
            v[a].insert(b);
            v[b].insert(a);
        }
        vector<bool> ans(26,false);
        queue<int> q;
        vector<int> arr(26,INT_MAX);
        arr[0]=0;
        for(int i=0;i<26;i++){
            if(!ans[i] &&  v[i].size()>0){
                set<int> s;
                queue<int> q;
                for(auto j :v[i]){
                    q.push(j);
                    ans[j] = true;
                }
                while(!q.empty()){
                    int size = q.size();
                    for(int j=0;j<size;j++){
                        int a = q.front();
                        q.pop();
                        s.insert(a);
                        for(auto x:v[a]){
                            if(!ans[x]){
                                s.insert(x);
                                ans[x] = true;
                                q.push(x);
                            }
                        }
                    }
                }
                int mini = INT_MAX;
                for(auto j:s){
                    mini = min(mini,j);
                    arr[j]= mini;
                }
            }
            
        }
        string s="";
        for(int i=0;i<baseStr.length();i++){
            int a = baseStr[i]-'a';
            if(arr[a]==INT_MAX) s+=('a'+a);
            else s+=('a'+arr[a]);
        }
        return s;
    }
};