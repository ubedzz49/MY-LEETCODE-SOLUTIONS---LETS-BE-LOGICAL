class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int def=0;
        for(int i=0;i<rolls.size();i++){
            def+=(mean-rolls[i]);
        }
        vector<int> vec;
        if(def>n*(6-mean)){
            return vec;
        }
        if(def>0){
        for(int i=n;i>0;i--){
            if(mean+0<=6 && def-0<=(i-1)*(6-mean)){
                vec.push_back(mean+0);
                def-=0;
                continue;
            }
            if(mean+1<=6 && def-1<=(i-1)*(6-mean)){
                vec.push_back(mean+1);
                def-=1;
                continue;
            }
            if(mean+2<=6 && def-2<=(i-1)*(6-mean)){
                vec.push_back(mean+2);
                def-=2;
                continue;
            }
            if(mean+3<=6 && def-3<=(i-1)*(6-mean)){
                vec.push_back(mean+3);
                def-=3;
                continue;
            }
            if(mean+4<=6 && def-4<=(i-1)*(6-mean)){
                vec.push_back(mean+4);
                def-=4;
                continue;
            }
            if(mean+5<=6 && def-5<=(i-1)*(6-mean)){
                vec.push_back(mean+5);
                def-=5;
                continue;
            }
            if(mean+6<=6 && def-6<=(i-1)*(6-mean)){
                vec.push_back(mean+6);
                def-=6;
                continue;
            }
        }
    }
    else if(def<0){
        def=-def;
        for(int i=n;i>0;i--){
            if(mean-0>0 && def-0<=(i-1)*(mean-1)){
                vec.push_back(mean-0);
                def-=0;
                continue;
            }
            if(mean-1>0 && def-1<=(i-1)*(mean-1)){
                vec.push_back(mean-1);
                def-=1;
                continue;
            }
            if(mean-2>0 && def-2<=(i-1)*(mean-1)){
                vec.push_back(mean-2);
                def-=2;
                continue;
            }
            if(mean-3>0 && def-3<=(i-1)*(mean-1)){
                vec.push_back(mean-3);
                def-=3;
                continue;
            }
            if(mean-4>6 && def-4<=(i-1)*(mean-1)){
                vec.push_back(mean-4);
                def-=4;
                continue;
            }
            if(mean-5>6 && def-5<=(i-1)*(mean-1)){
                vec.push_back(mean-5);
                def-=5;
                continue;
            }
            if(mean-6>6 && def-6<=(i-1)*(mean-1)){
                vec.push_back(mean-6);
                def-=6;
                continue;
            }
        }
    }
    else{
        vector<int> z(n,mean);
        return z;
    }
        return vec;
    }
};