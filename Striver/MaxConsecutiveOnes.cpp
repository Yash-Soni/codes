class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0, maxCount=0;
        for(int i=0; i<n; i++) {
          if(nums[i]) count++;
          else {
            maxCount=max(maxCount, count);
            count=0;
          }
        }
        maxCount=max(maxCount, count);
        return maxCount;
    }
};
