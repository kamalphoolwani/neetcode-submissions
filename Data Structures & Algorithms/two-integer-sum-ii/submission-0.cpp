class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, h = numbers.size()-1;
        while(l<h){
            int sum = numbers[l] + numbers[h];
            if(sum == target){
                return {l+1, h+1};
            }
            else if(sum<target)
                l++;
            else
                h--;
        }
        return {-1, -1};
    }
};
