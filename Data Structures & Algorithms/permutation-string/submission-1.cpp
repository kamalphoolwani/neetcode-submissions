class Solution {
    bool isValid(vector<int> &arr){
        for(const auto &i : arr){
            if(i != 0)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2)
            return false;
        vector<int> arr(26, 0);
        for(int i = 0; i<n1; i++){
            arr[s1[i]-'a']++;
        }
        int l = 0, r = 0;
        for(; r<n2;r++){
            arr[s2[r]-'a']--;
            if(r-l == n1-1){
                if(isValid(arr))
                    return true;
                arr[s2[l]-'a']++;
                l++;
            }
        }

        return false;
    }
};
