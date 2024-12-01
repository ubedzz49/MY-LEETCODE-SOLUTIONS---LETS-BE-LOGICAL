class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,bool> mpp;
        int c=0;
        for(auto it:arr){
            if(it==0){
                c++;
                continue;
            }
            mpp[it]=1;
        }
        for(auto it:arr){
            if(mpp[it*2]) return 1;
        }
        if(c>1) return 1;
        return 0;
    }
};