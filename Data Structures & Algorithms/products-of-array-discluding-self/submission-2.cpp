class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long product = 1;
        int isZero = 0;
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            if(nums[i]==0)
                isZero++;
            else
                product *= nums[i];
        }

        for(int i = 0; i<n; i++){
            if(nums[i]==0){
                ans[i] = isZero > 1 ? 0 : product;
            }
            else{
                if(isZero)
                    ans[i] = 0;
                else
                    ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};
