class Solution {
public:
int xorf(int m,int n){
    int mn=min(m,n);
    int mx=max(m,n);
    int c=0;
    int ans=0;
    while(mx>0){
        if(mx%2!=mn%2){
            ans+=pow(2,c);
        }
        c++;
        mx/=2;
        mn/=2;
    }
    return ans;
}
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors;
        int h=0;
        xors.push_back(h);
        for(int i=0;i<arr.size();i++){
            h=xorf(h,arr[i]);
            xors.push_back(h);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(xorf(xors[queries[i][0]],xors[queries[i][1]+1]));
        }
        return ans;
    }
};