class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> vec;
        if(n<3) return vec;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++) {
          int target=0-nums[i];
          int low=i+1, high=n-1;
          while(low<high) {
            int sum=nums[low]+nums[high];
            if(sum == target) {
              vec.push_back({nums[i], nums[low], nums[high]});
              int tem1=low, tem2=high;
              while(low<high && nums[tem1] == nums[low]) low++;
              while(high>low && nums[tem2] == nums[high]) high--;
            } else if(sum < target) {
              low++;
            } else high--;
          }
          while(i+1 < n-1 && nums[i] == nums[i+1]) i++;
        }
        return vec;
    }
};
