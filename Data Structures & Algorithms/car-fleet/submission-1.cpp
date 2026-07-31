class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> carInfo;

        for(int i = 0; i<n; i++){
            carInfo.push_back({position[i], speed[i]});
        }

        sort(carInfo.begin(), carInfo.end());
        double maxmTime = 0.0;
        int count = 0; 
        for(int i = n-1; i>=0; i--){
            double time = (1.0*target - 1.0*carInfo[i].first)/(1.0*carInfo[i].second);
            if(maxmTime!=0.0 and time <= maxmTime)
                continue;
            maxmTime = time;
            count++;
        }

        return count;
        
    }
};
