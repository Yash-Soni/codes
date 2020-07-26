static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        if(n == 0)
            return true;
        st.push(nums[0]);
        int count =0, i=1;
        bool flag = false;
        while(i<n)
        {
            if(nums[i] >= st.top())
                st.push(nums[i]);
            else
            {
                if(flag) return false;
                flag = true;
                int val = st.top();
                st.pop();
                if(st.size() == 0 || st.top() <= nums[i])
                    st.push(nums[i]);
                else
                    st.push(val);
            }
            i++;
        }
        return true;
    }
};
