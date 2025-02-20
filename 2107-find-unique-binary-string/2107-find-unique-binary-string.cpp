class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
      int n=nums[0].size();
      vector<string> vec;
      vec.push_back("");
      for(int i=0;i<n;i++){
        int s=vec.size();
        vector<string> vec2;
        for(int j=0;j<s;j++){
            vec2.push_back(vec[j]+'1');
            vec2.push_back(vec[j]+'0');
        }
        vec=vec2;
      }  
      unordered_map<string,bool> mpp;
      for(auto it:nums) mpp[it]=1;
      for(auto it:vec) if(mpp[it]==0) return it;
      return "";
    }
};