class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++){
            string sub = searchWord.substr(0,i+1);
            auto it =lower_bound(products.begin(), products.end(), sub);
            if(it==products.end()){
                ans.push_back({});
            }else{
                vector<string> search;
                int j=it-products.begin();
                int l=j+3;
                for(j=j;j<l && j<products.size();j++){
                    if((products[j].size()>=(i+1)) && products[j].substr(0,i+1)==sub){
                        search.push_back(products[j]);
                    }else{
                        break;
                    }
                }
                ans.push_back(search);
            }
        }
        return ans;
    }
};