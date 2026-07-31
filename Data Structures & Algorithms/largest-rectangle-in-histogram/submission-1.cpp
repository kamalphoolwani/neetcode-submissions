class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = INT_MIN;
        for(int i = 0; i<n; i++){
            while(!st.empty() and heights[i] <= heights[st.top()]){
                int popedIdx = st.top();
                st.pop();
                int prevIdx = st.empty() ? 0 : (st.top()+1);
                maxArea = max(heights[popedIdx]*(i - prevIdx), maxArea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int popedIdx = st.top();
            st.pop();
            int prevIdx = st.empty() ? 0 : (st.top()+1);
            maxArea = max(heights[popedIdx]*(n - prevIdx), maxArea);
        }

        return maxArea;
    }
};
