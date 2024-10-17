class Solution {
public:
    int maximumSwap(int num) {
        int num1=num;
        vector<int> nums;
        while(num>0){
            nums.push_back(num%10);
            num/=10;
        }
        reverse(nums.begin(),nums.end());
        priority_queue<int> pq;
        for(auto i:nums){
            pq.push(i);
        }
        int it=-1;
        int jt=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=pq.top()){
                it=pq.top();
                jt=nums[i];
                break;
            }
            pq.pop();
        }
        if(it==-1){
            return num1;
        }
        for(int i=0;i<nums.size();i++){
            if(jt==nums[i]){
                nums[i]=it;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==it){
                nums[i]=jt;
                break;
            }
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            ans+=(nums[i]*(pow(10,nums.size()-1-i)));
        }
        return ans;
    }
};