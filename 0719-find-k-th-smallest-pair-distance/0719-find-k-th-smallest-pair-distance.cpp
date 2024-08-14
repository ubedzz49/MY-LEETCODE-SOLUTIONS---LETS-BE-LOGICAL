class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        map<int,int> mpp;
        vector<int> vec(*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end())+1,0);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                vec[abs(nums[i]-nums[j])]++;
            }
        }
       for(int i=0;i<vec.size();i++){
        k-=vec[i];
        if(k<=0){
            return i;
        }
       }
        return -1;
    }
};