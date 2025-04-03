class Solution {
public:
struct comp{
    bool operator()(const string &a, const string &b) {
        if (a.size()!=b.size()) return a.size()<b.size();
        return a<b;
    }
};

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,comp> pq;
        for(auto it:nums) pq.push(it);
        while(k>1){
            k--;
            pq.pop();
        }
        return pq.top();
    }
};