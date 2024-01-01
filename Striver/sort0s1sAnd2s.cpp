class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;
        int zero=0, one=0, two=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==0) zero++;
            if(nums[i]==1) one++;
            if(nums[i]==2) two++;
        }
        for(int i=0; i<zero; i++) nums[i] = 0;
        for(int i=0; i<one; i++) nums[i+zero] = 1;
        for(int i=0; i<two; i++) nums[i+zero+one] = 2;
        return;
    }
};
