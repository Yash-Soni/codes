class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> vec;
        if(m==1 || n==1) return 1;
        for(int i=0; i<m; i++) {
            vector<int> v(n, -1);
            vec.push_back(v);
        }
        vec[m-1][n-2] = 1;
        vec[m-2][n-1] = 1;
        vec[m-1][n-1] = 0;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i == m-1 && vec[i][j] == -1) vec[i][j] = 1;
                if(j == n-1 && vec[i][j] == -1) vec[i][j] = 1;
                if(i!=m-1 && j!=n-1 && vec[i][j] == -1) {
                    vec[i][j] = vec[i+1][j] + vec[i][j+1];
                }
            }
        }
        return vec[0][0];
    }
};
