class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return tolower(c); });
        int i = 0, j = s.size()-1;
        while(i<j){
            if(isalnum(s[i])==false){
                i++;
                continue;
            }
            if(isalnum(s[j])==false){
                j--;
                continue;
            }

            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
};
