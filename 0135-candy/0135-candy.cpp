class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size();
        vector<int> left(n,1),right(n,1);
        
        for(int i=1;i<n;i++){
            if(rat[i-1]<rat[i]) left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(rat[i+1]<rat[i]) right[i]=right[i+1]+1;
        }
        for(int i=0;i<n;i++){
            left[i]=max(left[i],right[i]);
        }

        return accumulate(left.begin(),left.end(),0);
    }
};