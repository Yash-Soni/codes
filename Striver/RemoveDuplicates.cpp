class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1, len=nums.size();
        if(nums[0] == nums[len-1]) return j;
        if(len == 1) return j;
        for (int i=1; i<len; i++) {
            if(nums[i] != nums[i-1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
