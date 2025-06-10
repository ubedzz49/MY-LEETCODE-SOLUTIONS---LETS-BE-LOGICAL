class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mpp;
        for(auto it:s) mpp[it]++;
        int odmx=INT_MIN;
        int evmn=INT_MAX;
        for(auto it:mpp){
            if(it.second & 1){
                odmx=max(odmx,it.second);
            }
            else{
                evmn=min(evmn,it.second);
            }
        }
        return (odmx-evmn);
    }
};