class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);

        for(int i = 0; i<=amount; i++){
            if(i%coins[0]==0)
                prev[i] = 1;
        }

        for(int idx = 1; idx<n; idx++){
            vector<int> curr(amount+1, 0);
            for(int amt = 0; amt<=amount; amt++){
                int pick = 0, notPick = 0;
                if(coins[idx]<=amt){
                    pick = curr[amt-coins[idx]];
                }
                notPick = prev[amt];
                curr[amt] = pick + notPick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};
