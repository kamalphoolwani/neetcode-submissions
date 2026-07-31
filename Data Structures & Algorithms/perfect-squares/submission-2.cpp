class Solution {
public:
    int numSquares(int n) {
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i = 1; i<=n; i++)
            prev[i] = i;
        
        for(int idx = 2; idx*idx<=n; idx++){
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


// class Solution {
// public:
//     int numSquares(int n) {
//         // Initialize DP array with a large number
//         vector<int> dp(n + 1, INT_MAX);
        
//         // Base case: 0 requires 0 perfect squares
//         dp[0] = 0; 
        
//         for (int i = 1; i <= n; i++) {
//             // Check every perfect square less than or equal to i
//             for (int j = 1; j * j <= i; j++) {
//                 dp[i] = min(dp[i], 1 + dp[i - j * j]);
//             }
//         }
        
//         return dp[n];
//     }
// };