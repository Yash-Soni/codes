class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> vec;
        if(n<4) return vec;
        for(int i=0; i<n-3; i++) {
          for(int j=i+1; j<n-2; j++) {
            int low=j+1;
            int high=n-1;
            long long newTarget = (long long) target - (long long)nums[i] - (long long)nums[j];
            while(low<high) {
              int sum=0;
              sum = nums[low]+nums[high];
              if(sum==newTarget) {
                // vector<int> v;
                vec.push_back({nums[i], nums[j], nums[low], nums[high]});
                // vec.push_back(v);
                int tem1=low, tem2=high;
                while(low<high && nums[tem1]==nums[low]) low++;
                while(high>low && nums[tem2]==nums[high]) high--;
              } else if(sum < newTarget) {
                low++;
              } else {
                high--;
              }
            }
            while(j+1<n-1 && nums[j] == nums[j+1]) j++;
          }
          while(i+1<n-2 && nums[i] == nums[i+1]) i++;
        }
        
        return vec;
    }
};
