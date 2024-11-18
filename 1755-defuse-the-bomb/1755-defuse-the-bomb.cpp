class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k2) {
        if(k2==0) {vector<int>ans(code.size(),0); return ans;}
        vector<int> code1=code;
        int sum=0;
        int k=k2;
        if(k<0) k=-k2;
        for(int i=0;i<k;i++)sum+=code[i];
        for(int i=k;i<k+code.size();i++){
            cout<<i<<" ";
            if(k2<0) {code[(i)%code.size()]=sum;}
            int temp1=code1[(i-k)%code.size()]; 
            int temp2=code1[i%code.size()];
            
            sum+=temp2;
            sum-=temp1;
            if(k2>0) {code[(i-k)%code.size()]=sum;}
        }
        return code;
    }
};