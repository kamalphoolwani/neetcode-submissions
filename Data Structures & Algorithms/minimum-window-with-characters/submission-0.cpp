class Solution {
public:
    string minWindow(string s, string t) {
        int tSize = t.size();
        int sSize = s.size();
        vector<int> mp(256, 0);
        int cnt = 0, i = 0, j = 0, ans = INT_MAX, stIndex = -1;
        for(auto &ch : t){
            mp[ch]++;
        }

        while(j<sSize){
            if(mp[s[j]]>0){
                cnt++;
            }
            mp[s[j]]--;
            while(cnt == tSize){
                if(j-i+1 < ans){
                    ans = j - i + 1;
                    stIndex = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                    cnt = cnt - 1;
                i++;
            }
            j++;
        }
        if(ans == INT_MAX || stIndex==-1)
            return "";
        return s.substr(stIndex, ans);
    }
};
