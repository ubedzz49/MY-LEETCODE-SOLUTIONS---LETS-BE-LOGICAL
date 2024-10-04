class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int ip=*min_element(skill.begin(),skill.end());
        ip+=*max_element(skill.begin(),skill.end());
        sort(skill.begin(),skill.end());
        map<int,int> mpp;
        for(int i=0;i<skill.size();i++){
            mpp[ip-skill[i]]--;
            mpp[skill[i]]++;
        }
        for(auto i:mpp){
            if(i.second!=0){
                return -1;
            }
        }
        long long ans=0;
        while(skill.size()>0){
            ans+=(skill[0]*skill[skill.size()-1]);
            skill.erase(skill.begin());
            skill.erase(skill.end());
            
        }
        return ans;
    }
};