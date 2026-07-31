class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double> st;
        vector<pair<int, int>> carInfo;

        for(int i = 0; i<n; i++){
            carInfo.push_back({position[i], speed[i]});
        }

        sort(carInfo.begin(), carInfo.end());

        for(int i = n-1; i>=0; i--){
            double time = (1.0*target - 1.0*carInfo[i].first)/(1.0*carInfo[i].second);
            if(!st.empty() and time <= st.top())
                continue;
            st.push(time);
        }

        return st.size();
        
    }
};


//{0, 1} {1, 2}, {4, 2}, {7, 1}
