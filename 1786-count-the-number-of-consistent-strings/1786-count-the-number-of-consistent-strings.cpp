class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c=0;
        for(int i=0;i<words.size();i++){
            c++;
            for(int j=0;j<words[i].size();j++){
                if(!allowed.contains(words[i][j])){
                    c--;
                    break;
                }
            }
        }
        return c;
    }
};