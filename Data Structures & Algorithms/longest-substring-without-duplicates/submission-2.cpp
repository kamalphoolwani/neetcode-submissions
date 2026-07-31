class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256, -1);
        int ans = 0;
        int st = 0, end = 0;
        for(int end = 0; end<s.size(); end++){
            if(arr[s[end]] != -1)
                st = max(arr[s[end]]+1, st); 
            arr[s[end]] = end;
            ans = max(ans, end - st + 1);
        }
        
        return ans;
    }
};
