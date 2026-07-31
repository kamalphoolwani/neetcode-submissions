
class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string encode = "";
        for(auto &s : strs){
            encode += to_string(s.size()) + "#" + s;
        }
        return encode;
    }

    vector<string> decode(string s) {
        vector<string> decode;
        int n = s.size();
        int i = 0;
        while(i<n){
            int j  = i;
            while(s[j]!='#'){
                j++;
            }

            int len = stoi(s.substr(i, j-i));
            i = j+1;
            decode.push_back(s.substr(i, len));
            i += len;
        }
        return decode;
    }
};
