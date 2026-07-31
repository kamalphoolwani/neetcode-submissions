class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> curr(m+1, 0);
        curr[0] = 1;
        
        for(int i = 1; i<=n; i++){
            for(int j = m; j>=1; j--){
                int pick = 0, notPick = 0;
                if(s[i-1]==t[j-1])
                    pick = curr[j-1];

                notPick = curr[j];
                curr[j] = pick + notPick;
            }
        }
        return curr[m];
    }
};
