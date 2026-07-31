class Solution {
    bool isValid(int currH, vector<int>& piles, int &h){
        int n = piles.size();
        int hCount = 0;
        for(int i = 0; i<n; i++){
            hCount += ceil(piles[i]/(1.0*currH));
            if(hCount > h)
                return false;
        }

        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxm = *max_element(piles.begin(), piles.end());
        int l = 1, r = maxm;
        int ans = maxm;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isValid(mid, piles, h)){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
