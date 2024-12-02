class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word="";
        int c=1;
        for(auto it:sentence){
            if(it==' ') {word="";c++;}
            else{
                word+=it;
                if(word==searchWord) return c;
            }
        }
       return -1; 
    }
};