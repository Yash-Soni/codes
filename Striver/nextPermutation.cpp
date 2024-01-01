class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        if(n==2) {
            int tem=nums[1];
            nums[1] = nums[0];
            nums[0] = tem;
            return;
        }
        bool desc=true;
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                desc = false;
                break;
            }
        }
        if(desc) {
            reverse(nums.begin(), nums.end());
            return;    
        }
        int i=n-2, j=n-1;
        while(i>=0 && nums[i] >= nums[i+1]) {
            i--;
        }
        while(j>i && nums[j] <= nums[i]) j--;

        swap(nums[i], nums[j]);
        
        reverse(nums.begin()+i+1, nums.end());
    }
};
