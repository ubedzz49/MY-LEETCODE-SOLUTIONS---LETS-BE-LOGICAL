class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string a="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(a!=""){
                    words.push(a);
                    a="";
                }
            }else{
                a+=s[i];
            }
            if(i==s.size()-1 && a!=""){
                words.push(a);
            }
        }
string ans=words.top();
words.pop();
while(!words.empty()){
    ans+=" ";
    ans+=words.top();
    words.pop();
}
        return ans;
    }
};