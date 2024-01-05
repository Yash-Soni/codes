class Solution {
public:
    bool getColIndex(int low, int high, int target, int rowIndex, vector<vector<int>>& matrix) {
        bool res;
        if(low<high) {
            int mid = low+(high-low)/2;
            if(matrix[rowIndex][mid] == target) {
                return true;
            } else if(matrix[rowIndex][mid] > target) {
                res = getColIndex(low, mid, target, rowIndex, matrix);
            } else {
                cout<<"\nhere it is: "<<matrix[rowIndex][mid];
                res = getColIndex(mid+1, high, target, rowIndex, matrix);
            }
        } else return false;
        return res;
    }

    int getRowIndex(int low, int high, int target, vector<vector<int>>& matrix) {
        int index;
        if(low<high) {
            int mid=low+(high-low)/2;
            if(matrix[mid][0] >= target) {
                if(matrix[mid][0] == target) return mid;
                if(mid>0 && matrix[mid-1][0] < target) {
                    return mid-1;
                }
                index = getRowIndex(low, mid, target, matrix);
            } else {
                index = getRowIndex(mid+1, high, target, matrix);
            }
        }
        return index;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==1 && n==1) {
            return matrix[0][0] == target;
        }
        bool res;
        int rowInd;
        if(m==1) {
            res = getColIndex(0, n, target, 0, matrix);
        } else if(n==1) {
            rowInd = getRowIndex(0, m, target, matrix);
            return matrix[rowInd][0] == target;
        } 
        else {
            rowInd = getRowIndex(0, m, target, matrix);
            res = getColIndex(0, n, target, rowInd, matrix);
        }
        // cout<<"RowIndex: "<<rowInd;
        return res;
    }
};
