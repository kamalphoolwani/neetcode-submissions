// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> prev(n+1, 0), curr(n+1, 0);
        
//         for(int i = 1; i<=n; i++)
//             prev[i] = i;
        
//         for(int idx = 2; idx*idx<=n; idx++){
//             for(int num = 1; num<=n; num++){
//                 int pick = INT_MAX, notPick = INT_MAX;
//                 if(idx * idx <= num){
//                     pick = 1 + curr[num - (idx*idx)];
//                 }
//                 notPick = prev[num];

//                 curr[num] = min(pick, notPick);
//             }
//             prev = curr;
//         }
        
//         return prev[n];
//     }

// };
#include <cmath>

class Solution {
private:
    // Helper to check if a number is a perfect square
    bool isPerfectSquare(int n) {
        int root = sqrt(n);
        return root * root == n;
    }

public:
    int numSquares(int n) {
        // Step 1: Is it 1?
        if (isPerfectSquare(n)) {
            return 1;
        }

        // Step 2: Is it 4? (Legendre's Theorem: n = 4^a * (8b + 7))
        int temp = n;
        while (temp % 4 == 0) {
            temp /= 4;
        }
        if (temp % 8 == 7) {
            return 4;
        }

        // Step 3: Is it 2? 
        for (int i = 1; i * i <= n; i++) {
            if (isPerfectSquare(n - i * i)) {
                return 2;
            }
        }

        // Step 4: By elimination, it must be 3
        return 3;
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