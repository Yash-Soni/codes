class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n=intervals.size();
        vector<pair<int, int>> pairs;
        for(int i=0; i<n; i++) {
            pair<int, int> p;
            p.first=intervals[i][0];
            p.second=intervals[i][1];
            pairs.push_back(p);
        }
        sort(pairs.begin(), pairs.end());
        int first=pairs[0].first, second = pairs[0].second;
        for(int i=1; i<n; i++) {
            vector<int> tem(2);
            if(second >= pairs[i].first) {
                second = max(pairs[i].second, second);
            } else {
                tem[0]=first;
                tem[1]=second;
                first = pairs[i].first;
                second = pairs[i].second;
                result.push_back(tem);
            }
        }
        result.push_back({first, second});
        return result;
    }
};
