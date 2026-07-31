class Solution {
    // int func(int idx, string &s, unordered_set<string> &st, vector<int> &dp)
    // {
    //     int n = s.size();
    //     if(idx==n)
    //         return 0;
    //     if(dp[idx] != -1)
    //         return dp[idx];
    //     int minm = n - idx;
    //     string curr = "";
    //     for(int i = idx; i<n; i++){
    //         curr += s[i];
    //         if(st.find(curr) != st.end()){
    //             minm = min(func(i+1, s, st, dp), minm);
    //         }
    //         else{
    //             minm = min((i - idx + 1) + min(func(i+1, s, st, dp), minm), minm);
    //         }
    //     }
    //     return dp[idx]=minm;
    // }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(n+1, 0);

        for(int idx = n-1; idx>=0; idx--){
            int minm = n - idx;
            string curr = "";
            for(int i = idx; i<n; i++){
                curr += s[i];
                if(st.find(curr) != st.end()){
                    minm = min(dp[i+1], minm);
                }
                else{
                    minm = min((i - idx + 1) + dp[i+1], minm);
                }
            }
            dp[idx]=minm;
        }
        return dp[0];
    }
};