class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tg) {
        map<int,pair<int,vector<int>>> mpp;
        priority_queue<int, vector<int>,greater<int>> pq;
        for(int i=0;i<times.size();i++){
            mpp[times[i][0]].first=i+1;
            mpp[times[i][1]].second.push_back(i+1);
            pq.push(i+1);
        }
        bool b=false;
        vector<int> sitting(times.size()+1,-1);
        for(auto i:mpp){
            for(auto j:i.second.second){
                pq.push(sitting[j]);
            }
           if(i.second.first==0){
            continue;
           }
            sitting[i.second.first]=pq.top();
            pq.pop();
        }

        for(auto i:mpp){
            cout<<"for "<<i.first<<" -> ";
            cout<<"coming are "<<i.second.first<<" at "<<sitting[i.second.first]<<" and going are ";
            for(auto j:i.second.second) cout<<j<<" ";
            cout<<endl;
        }



        for(auto i:sitting) cout<<i<<" ";
        return sitting[tg+1]-1;
    }
};