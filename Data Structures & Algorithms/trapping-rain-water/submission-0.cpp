class Solution {
public:
    int trap(vector<int>& heights) {
        int r = 0, l = heights.size() - 1, ans = 0;
        int maxR = heights[0], maxL = heights[l];
        while(r<l){
            if(heights[r]<=heights[l]){
                if(maxR>heights[r])
                    ans += maxR - heights[r];
                else
                    maxR = heights[r];
                r++;
            }
            else{
                if(maxL>heights[l])
                    ans += maxL - heights[l];
                else
                    maxL = heights[l];
                l--;
            }
        }
        return ans;
    }
};
