class Solution {
public:
    void merge(int& count, int low, int mid, int high, vector<int>& nums) {
        int i=low, j=mid+1;

        while(i<=mid) {
            while(j<=high && nums[i] > (long long)2*nums[j]) {
                j++;
            }
            count += (j-mid-1);
            i++;
        }

        vector<int> tem;
        i=low, j=mid+1;

        while(i<=mid && j<=high) {
            if(nums[i] < nums[j]) {
                tem.push_back(nums[i++]);
            } else {
                tem.push_back(nums[j++]);
            }
        }

        while(i<=mid) {
            tem.push_back(nums[i++]);
        }
        while(j<=high) {
            tem.push_back(nums[j++]);
        }

        for(int i=low; i<=high; i++) {
            nums[i] = tem[i-low];
        }
    }

    void mergeSort(int& count, int low, int high, vector<int>& nums) {
        if(low >= high) return;
        int mid=low+(high-low)/2;

        mergeSort(count, low, mid, nums);
        mergeSort(count, mid+1, high, nums);
        merge(count, low, mid, high, nums);
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        mergeSort(count, 0, n-1, nums);        
        return count;
    }
};
