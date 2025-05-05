class Solution {
public:
    int compareVersion(string a, string b) {
       int i=0;int j=0;
       while(!(i==a.size() && j==b.size())){
        string aa="", bb="";
        while(i!=a.size()){
            if(a[i]=='.'){
                i++;
                break;
            }
            aa+=a[i];
            i++;
        }
        while(j!=b.size()){
            if(b[j]=='.'){
                j++;
                break;
            }
            bb+=b[j];
            j++;
        }
        if(aa=="") aa="0";
        if(bb=="") bb="0";
        int x= stoi(aa);
        int y=stoi(bb);
        if(x>y) return 1;
        if(x<y) return -1;
       }
       return 0;
    }
};