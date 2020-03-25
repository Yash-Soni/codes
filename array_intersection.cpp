class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_multiset<int> hashTable;
        for(int i: nums1)
            hashTable.insert(i);
        vector<int> res;
        for(int i: nums2) {
            const unordered_multiset<int>::iterator pointer = hashTable.find(i);
            if (pointer != hashTable.end()) {
                res.push_back(i);
                hashTable.erase(pointer);
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        vector<int> v;
        int p,q;
        p = nums1.size();
        q = nums2.size();
        int i,j;
        for(int i = 0;i<p;i++)
        {
            int count = 0,count1=0;
            if(m[nums1[i]] != 0)
            {
                j = m[nums1[i]];
            }
            else
                j = 0;
            for(j;j<q;j++)
            {
                if(nums1[i] == nums2[j])
                {
                    m[nums1[i]] = j+1;
                    v.push_back(nums1[i]);
                    break;
                }
            }
        }
        return v;
    }
};