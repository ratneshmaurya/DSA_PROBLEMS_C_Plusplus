// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         assuming 2d array as a 1d array
        int rows=matrix.size();
        int cols=matrix[0].size();
        int l=0,r=(rows*cols)-1;
        int mid;
        while(l<=r){
            
            mid=l+(r-l)/2;
            
            if(matrix[mid/cols][mid%cols]==target)
                return true;
            else if(matrix[mid/cols][mid%cols]>target)
                r=mid-1;
            else 
                l=mid+1;
        }
        return false;
    }
};