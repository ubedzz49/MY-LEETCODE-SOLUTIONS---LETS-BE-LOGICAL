class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<=j){
            ans=max(ans,(min(height[i],height[j])*(j-i)));
            if(min(height[i],height[j])==height[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};