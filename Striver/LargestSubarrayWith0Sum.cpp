class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int len=0, sum=0;
        vector<int> vec;
        // unordered_set<int> set;
        unordered_map<int, int> map;
        for(int i=0; i<n; i++) {
            sum += A[i];
            vec.push_back(sum);
        }
        int maxlen=0;
        map.insert({0, 0});
        
        for(int i=0; i<n; i++) {
            auto it = map.find(vec[i]);
            if(it != map.end()) {
                len = i+1-it->second;
                maxlen = max(maxlen, len);
            } else map.insert({vec[i], i+1});
            
        }
        return maxlen;
    }
};
