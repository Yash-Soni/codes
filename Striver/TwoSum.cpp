class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n=nums.size(), pos;
        map<int, int> m;
        m[nums[0]]=0;
        for(int i=1; i<n; i++) {
            int num = target-nums[i];
            if(m.find(num) != m.end()) {
                result.push_back(m[num]);
                result.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return result;
    }
};
