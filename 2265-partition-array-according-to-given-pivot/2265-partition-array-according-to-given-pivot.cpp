class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int e=0;
        vector<int> gr,a;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) a.push_back(nums[i]);
            if(nums[i]==pivot) e++;
            else if(nums[i]>pivot)gr.push_back(nums[i]);
            // nums.erase(nums.begin()+i);
            //i--;
        }
        nums={};
        for(auto it:a) nums.push_back(it);
        while(e>0){
            e--;
            nums.push_back(pivot);
        }
        for(auto it:gr)nums.push_back(it);
        return nums;
    }
};