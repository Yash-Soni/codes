class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, maxSum=INT_MIN, maxHere=INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            sum += nums[i];
            sum = max(sum, nums[i]);
            if(maxHere < sum) maxHere = sum;
            if(maxSum < maxHere) maxSum=maxHere;
        }
        return maxSum;
    }
};
