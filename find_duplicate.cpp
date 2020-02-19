class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup,i,n;
        n = nums.size();
        for(i=0;i<n;i++)
        {
            if(nums[abs(nums[i])] > 0)
            {
                nums[abs(nums[i])] = -1*nums[abs(nums[i])];
            }
            else
            {
                dup = abs(nums[i]);
                break;
            }
        }
        return dup;

    }
};