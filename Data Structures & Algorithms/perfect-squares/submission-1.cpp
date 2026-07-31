class Solution {
public:
    int numSquares(int n) {
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i = 1; i<=n; i++)
            prev[i] = i;
        
        for(int idx = 2; idx<=100; idx++){
            for(int num = 1; num<=n; num++){
                int pick = INT_MAX, notPick = INT_MAX;
                if(idx * idx <= num){
                    pick = 1 + curr[num - (idx*idx)];
                }
                notPick = prev[num];

                curr[num] = min(pick, notPick);
            }
            prev = curr;
        }
        
        return prev[n];
    }

};