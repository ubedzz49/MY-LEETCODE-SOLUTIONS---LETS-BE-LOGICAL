class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mpp;
        for(auto it:s) mpp[it]++;
        int odmx=INT_MIN;
        int odmn=INT_MAX;
        int evmx=INT_MIN;
        int evmn=INT_MAX;
        for(auto it:mpp){
            if(it.second & 1){
                odmn=min(odmn,it.second);
                odmx=max(odmx,it.second);
            }
            else{
                evmn=min(evmn,it.second);
                evmx=max(evmx,it.second);
            }
        }
        return (odmx-evmn);
    }
};