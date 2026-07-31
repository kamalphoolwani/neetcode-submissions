class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1!=n2)
            return false;
        
        vector<int> arr(256, 0);
        for(int i = 0; i<n1; i++){
            arr[s[i]]++;
            arr[t[i]]--;
        }

        for(int i = 0; i<=255; i++){
            if(arr[i])
                return false;
        }
            
        return true;
    }
};
