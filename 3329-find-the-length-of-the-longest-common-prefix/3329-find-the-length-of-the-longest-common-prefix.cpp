class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<int,bool> mpp;
        for(int i=0;i<arr1.size();i++){
            int n=arr1[i];
            while(n>0){
                mpp[n]=1;
                n/=10;
            }
        }
        int lar=0;
        for(int i=0;i<arr2.size();i++){
            int n=arr2[i];
            while(n>0){
                if(mpp[n]){
                    lar=max(lar,n);
                }
                n/=10;
            }
        }
        if(lar==0){
            return 0;
        }
        string s=to_string(lar);
        return s.size();
    }
};