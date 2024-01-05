// Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(), count=0, candidate=nums[0];
        if(n<3) return nums[0];
        for(int i=0; i<n; i++){
            if(candidate == nums[i]) count++;
            else {
                count--;
                if(count<0) {
                    candidate = nums[i];
                    count=0;
                }
            }
        }
        return candidate;
    }
};
