// Boyer-Moore Majority vote Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        if(n==1) return nums;

        int c1=INT_MIN, c2=INT_MIN, count1=0, count2=0, minOccurences = n/3;
        for(int i=0; i<n; i++) {
            if(count1 == 0 && nums[i] != c2) {
                count1++;
                c1=nums[i];
            } else if(count2==0 && nums[i] != c1) {
                count2++;
                c2=nums[i];
            } else if(nums[i] == c1) count1++;
            else if(nums[i] == c2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1=0; count2=0;
        for(int i=0; i<n; i++) {
            if(nums[i] == c1) count1++;
            if(nums[i] == c2) count2++;
        }

        if(count1 > minOccurences) res.push_back(c1);
        if(count2 > minOccurences) res.push_back(c2);

        return res;
    }
};
