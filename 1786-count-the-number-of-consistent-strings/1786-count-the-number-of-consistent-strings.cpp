class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int> mpp;
        for(int i=0;i<allowed.size();i++){
            mpp[allowed[i]]++;
        }
        int c=0;
        for(int i=0;i<words.size();i++){
            c++;
            for(int j=0;j<words[i].size();j++){
                if(mpp[words[i][j]]==0){
                    c--;
                    break;
                }
            }
        }
        return c;
    }
};