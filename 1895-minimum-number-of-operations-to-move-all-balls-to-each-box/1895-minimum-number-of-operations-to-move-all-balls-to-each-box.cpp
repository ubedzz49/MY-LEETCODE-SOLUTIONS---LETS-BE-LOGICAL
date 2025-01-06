class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size());

        int travel=0,ones=0;
        for(int i=0;i<boxes.size();i++)
        {
                travel=travel+ones;
                ans[i]=travel;
                if(boxes[i]=='1')
                    ones++;
        }
        travel=0,ones=0;
        for(int i=boxes.size()-1;i>=0;i--)
        {
                travel=travel+ones;
                ans[i]=ans[i]+travel;
                if(boxes[i]=='1')
                    ones++;
        }
        return ans;

    }
};