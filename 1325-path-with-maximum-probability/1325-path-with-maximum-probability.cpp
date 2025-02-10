class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int s, int e) {
        vector<double> sp(n,0);
        sp[s]=1;
        int b=true;
        while(n>0 && b){
            b=false;
            n--;
            for(int i=0;i<edges.size();i++){
                if(sp[edges[i][1]]<sp[edges[i][0]]*prob[i]){ sp[edges[i][1]]=sp[edges[i][0]]*prob[i]; b=true;}
                if(sp[edges[i][0]]<sp[edges[i][1]]*prob[i]){ sp[edges[i][0]]=sp[edges[i][1]]*prob[i]; b=true;}
            }
        }
        return sp[e];
    }
};