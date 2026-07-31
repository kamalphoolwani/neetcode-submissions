class Solution {
    // bool func(int ind, int &n, string &s,  unordered_set<string> &st, vector<int> &dp)
    // {
    //     if(ind==n)
    //         return true;
    //     if(dp[ind]!=-1)
    //         return dp[ind];
    //     string temp = "";
    //     for(int i = ind; i<n; i++){
    //         temp += s[i];
    //         if(st.find(temp) != st.end()){
    //             if(func(i+1, n, s, st, dp))
    //                 return dp[ind] = true;
    //         }
    //     }

    //     return dp[ind] = false;
    // }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        dp[n] = true;
        for(int ind = n-1; ind>=0; ind--){
            string temp = "";
            bool found = false;
            for(int i = ind; i<n; i++){
                temp += s[i];
                if(st.find(temp) != st.end()){
                    if(dp[i+1]){
                        dp[ind] = true;
                        found = true;
                        break;
                    }
                }
            }
            if(!found)
                dp[ind] = false;

        }
        return dp[0];
    }
};
