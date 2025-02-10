class Solution {
public:
    bool checkValidString(string s) {
       unordered_map<int,bool> mpp;
       mpp[0]=1;
       for(auto it:s){
        unordered_map<int,bool> mpp2;
        if(it=='('){
           for(auto it:mpp) mpp2[it.first+1]=1; 
        }
        else if(it==')'){
            for(auto it:mpp) if(it.first-1>=0) mpp2[it.first-1]=1;
        }
        else{
            for(auto it:mpp){
                mpp2[it.first]=1;
                if(it.first-1>=0) mpp2[it.first-1]=1;
                mpp2[it.first+1]=1;
            }
        }
        mpp=mpp2;
       }
       return mpp[0];
    }
};