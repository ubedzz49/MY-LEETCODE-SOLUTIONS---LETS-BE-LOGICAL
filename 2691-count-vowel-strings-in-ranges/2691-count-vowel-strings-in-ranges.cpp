class Solution {
public:
bool isval(string s){
    if(s[0]!='a' && s[0]!='e' && s[0]!='i' && s[0]!='o' && s[0]!='u'){
        return 0;
    }
      if(s[s.size()-1]!='a' && s[s.size()-1]!='e' && s[s.size()-1]!='i' && s[s.size()-1]!='o' && s[s.size()-1]!='u'){
        return 0;
    }
    return 1;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> nums; vector<int> ans; vector<bool> isv;
        int c=0;
        for(int i=0;i<words.size();i++){
            bool b=0;
            nums.push_back(c);
            if(isval(words[i])){ c++; b=1;}
            isv.push_back(b);
        }
        for(int i=0;i<queries.size();i++){
            ans.push_back(nums[queries[i][1]]-nums[queries[i][0]]);
            if(isv[queries[i][1]]) ans[i]++;
        }
        return ans;
    }
};