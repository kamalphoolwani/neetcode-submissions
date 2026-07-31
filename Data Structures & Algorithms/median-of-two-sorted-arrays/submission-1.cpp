class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n)
            return findMedianSortedArrays(nums2, nums1);
        
        int totalLen = m + n;
        int cut = (totalLen + 1)/2;
        int l = 0, r  = m;

        while(l<=r){
            int mid = l + (r - l)/2;
            int l1 = (mid > 0) ? nums1[mid-1] : INT_MIN;
            int r1 = (mid < m) ? nums1[mid] : INT_MAX;
            int mid2 = cut - mid;
            int l2 = (mid2 > 0) ? nums2[mid2-1]: INT_MIN;
            int r2 = (mid2 < n) ? nums2[mid2] : INT_MAX;

            if(l1<= r2 and l2<=r1){
                if(totalLen%2)
                    return max(l1, l2);

                return (max(l1, l2) + min(r1, r2))/2.0;
            }

            else if(l1>r2){
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return -1;
    }
};
