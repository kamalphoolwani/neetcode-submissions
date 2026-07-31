class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int area = 0;
        while(l<r){
            int curr = min(heights[l], heights[r]) * (r - l);
            area = max(area, curr);
            if(heights[l]< heights[r])
                l++;
            else
                r--;
        }

        return area;
    }
};
