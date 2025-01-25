class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> copyNums = nums;
        sort(copyNums.begin(), copyNums.end());

        unordered_map<int, int>numGroup;
        numGroup[copyNums[0]] = 0;

        unordered_map<int, queue<int>> chainedGroup;
        chainedGroup[0].push(copyNums[0]);

        int currGroup = 0;

        for(int i = 1; i < n; i++){
            if(copyNums[i] - copyNums[i-1] > limit){
                currGroup++;
            }
            numGroup[copyNums[i]] = currGroup;
            chainedGroup[currGroup].push(copyNums[i]); 
        }

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int currNumGroup = numGroup[num];

            int newNum = chainedGroup[currNumGroup].front();
            chainedGroup[currNumGroup].pop();

            nums[i] = newNum;
        }

        return nums;
    }
};