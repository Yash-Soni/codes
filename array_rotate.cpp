class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i,n,j,tem;
        n = nums.size();
        /*while(k--)
        {
            tem = nums[0];
            nums[0] = nums[n-1];
            for(i=1;i<n;i++)
            {
                tem1 = nums[i];
                nums[i] = tem;
                tem = tem1;
            }
        }*/
        if(k>n)
        {
          k = k%n;
        }
        
        for(i=0,j = n-1;i<=j;i++,j--)
        {
            tem = nums[j];
            nums[j] = nums[i];
            nums[i] = tem;
        }
        for(i=k,j=n-1; i<=j;i++,j--)
        {
            tem= nums[j];
            nums[j] = nums[i];
            nums[i] = tem;
        }
        for(i=0,j=k-1;i<=j;i++,j--)
        {
            tem= nums[j];
            nums[j] = nums[i];
            nums[i] = tem;
        }
    }
};