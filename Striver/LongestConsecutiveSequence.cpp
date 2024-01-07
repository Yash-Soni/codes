class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxCount=0;
        unordered_set<int> set;
        for(int i=0; i<n; i++) {
            set.insert(nums[i]);
        }
        for(int num: nums) {
            if(set.find(num-1) == set.end()) {
                int count=1;
                int currentNum=num;
                while(set.find(currentNum+1) != set.end()) {
                    count++;
                    currentNum++;
                }
                maxCount = max(count, maxCount);
            }
        }
        return maxCount;
    }
};
