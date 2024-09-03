class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            int m=(s[i]-'a');
            m++;
            sum+=(m/10);
            sum+=(m%10);
        }
        k--;
        while(k!=0){
            k--;
            int n=0;
            n+=(sum/1000);
            sum=sum%1000;
            n+=(sum/100);
            sum=sum%100;
            n+=(sum/10);
            sum=sum%10;
            n+=sum;
            sum=n;
            cout<<n<<endl;
        }
        return sum;
    }
};