class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        vector<int> pref(words.size(),0);
        if(isVowel(words[0][0]) && isVowel(words[0][words[0].size()-1])){
            pref[0] = 1;
        }else{
            pref[0] = 0;
        }

        for(int i=1;i<words.size();i++){
            int n = words[i].size();
            if(isVowel(words[i][0]) && isVowel(words[i][n-1])) pref[i]+=(1+pref[i-1]);
            else pref[i]+=pref[i-1];
        }

        if(left==0) return pref[right];
        return pref[right]-pref[left-1];
    }

    bool isVowel(char c){
        return c=='a' || c=='e'|| c=='i' || c=='o' || c=='u';
    }
};