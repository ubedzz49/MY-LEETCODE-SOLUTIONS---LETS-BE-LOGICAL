class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>graph;
        unordered_map<string, int> indeg;
        
        for(int i=0; i<recipes.size(); i++){
            for(auto ing: ingredients[i]){
                graph[ing].push_back(recipes[i]);
                indeg[recipes[i]]++;
            }
        }

        vector<string>res;
        queue<string>q;
        for(auto it: supplies)
            q.push(it);

        while(!q.empty()){
            string item  = q.front();
            q.pop();

            if(find(recipes.begin(), recipes.end(), item) != recipes.end()){
                res.push_back(item);
            }

            for(auto bigger_item: graph[item]){
                if(--indeg[bigger_item] == 0){
                    q.push(bigger_item);
                }
            }
        }
        return res;
    }
};