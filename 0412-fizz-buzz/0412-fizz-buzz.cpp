class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n,"FizzBuzz");
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0) continue;
            if(i%3==0) ans[i-1]="Fizz";
            else if(i%5==0) ans[i-1]="Buzz";
            else ans[i-1]=to_string(i);
        }
        return ans;
    }
};