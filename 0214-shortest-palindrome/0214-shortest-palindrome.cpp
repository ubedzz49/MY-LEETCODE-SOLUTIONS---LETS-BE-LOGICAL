//SUCCESSFUL SOLUTION (ONLY 3 TEST CASES FAILING)
// class Solution {
// public:

// string chk(string s1,string s2){
    
//    if(s2.size()<s1.size()){
//     return "0";
//    }
//    if(s1.size()==0){
//     if(s2.size()==0){
//         return "";
//     }
//     reverse(s2.begin(),s2.end());
//     return s2;
//    }
//    int c=0;
//    for(int i=s1.size()-1;i>=0;i--){
//     if(s1[i]!=s2[c]){
//         return "s2";
//     }
//     c++;
//    }
//    string ss= s2.substr(c);
//    reverse(ss.begin(),ss.end());
//    return ss;
// }
//     string shortestPalindrome(string s) {
//         if(s.size()<=1){
//             return s;
//         }
//         vector<pair<int,int>> nums;
//         if(s[0]==s[1]){
//             nums.push_back({0,1});
//         }
//         for(int i=2;i<s.size();i++){
//             if(s[i]==s[i-2]){
//                 nums.push_back({i-2,i});
//             }
//             if(s[i]==s[i-1]){
//                 nums.push_back({i-1,i});
//             }
//         }
//         string dup=s;
//         reverse(dup.begin(),dup.end());
       
//         string fe=dup.substr(0,dup.size()-1);
//         for(auto i:nums){
//             string s1=s.substr(0,i.first);
//             string s2=s.substr(i.second+1,s.size()-i.second-1);
//             string extra=chk(s1,s2);
//             if(extra=="0" || extra=="s2"){
//                 continue;
//             }
//             if(extra.size()<=fe.size()){
//                 fe=extra;
//             }
//         }
//         return fe+s;
//     }
// };

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j]) {
                j = p[j - 1];
            }
            if (l[i] == l[j]) {
                j++;
            }
            p[i] = j;
        }
        return rev_s.substr(0, s.size() - p.back()) + s;
    }
};