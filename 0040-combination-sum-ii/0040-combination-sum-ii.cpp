class Solution {
    public:
        void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& path, int start) {
                if(target == 0){
                            res.push_back(path);
                                        return;
                                                }
                                                        for(int i = start; i < candidates.size(); i++){
                                                                    if(i > start && candidates[i] == candidates[i-1]){
                                                                                    continue;
                                                                                                }
                                                                                                            if (candidates[i] > target){
                                                                                                                            break;
                                                                                                                                        }
                                                                                                                                                    path.push_back(candidates[i]);
                                                                                                                                                                backtrack(candidates, target - candidates[i], res, path, i+1);
                                                                                                                                                                            path.pop_back();
                                                                                                                                                                                    }
                                                                                                                                                                                        }

                                                                                                                                                                                            vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                                                                                                                                                                                                    sort(candidates.begin(), candidates.end());
                                                                                                                                                                                                            vector<vector<int>> res;
                                                                                                                                                                                                                    vector<int> path;
                                                                                                                                                                                                                            backtrack(candidates, target, res, path, 0);
                                                                                                                                                                                                                                    return res;
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                        };
