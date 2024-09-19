class Solution {
public:

     unordered_map<string,vector<int>> mp;
    vector<int> diffWaysToCompute(string expression) {
         vector<int>ans;
         if(mp.find(expression)!=mp.end()){
                    return mp[expression];
                }
           for(int i=0;i<expression.size();i++){ 
              char curr=expression[i]; 
              if( curr=='+'||  curr=='-'|| curr=='*'){
                vector<int>left,right;
                  left = diffWaysToCompute(expression.substr(0,i));
                  right = diffWaysToCompute(expression.substr(i+1));
        
                for(auto i:left){
                    for(auto j:right){
                      if(curr=='+') ans.push_back(i+j);
                      else if(curr=='*')ans.push_back(i*j);
                      else ans.push_back(i-j);
                    }
                }
              }
          }
          if(ans.empty()){
            ans.push_back(stoi(expression));
          }
          mp[expression]=ans;
          return    mp[expression];}
};