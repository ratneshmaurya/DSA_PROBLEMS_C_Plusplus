//Approach 1 -- if want to use a sapce , then take an empty 2d matrix and simply copy given matrix ka row in the 
//columnwise order in that empty matrix. 

//Approach 2 (without using sapce)===  We first transpose the given matrix, and then reverse the content of individual rows to
//get the resultant 90 degree clockwise rotated matrix.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int r=matrix.size();
        int c=matrix[0].size();
        
        //first doing transpose
        for(int i=0;i<r;i++){
            for(int j=i;j<c;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //now doing reverse of each row
        int left,right;
        for(int i=0;i<r;i++){
            left=0,right=c-1; // using two pointer theorem like in 1D array for reversing each row.
            while(left<right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }

        // you can simply write second for loop also as (just in two lines) ---- does same work in same time complexity
        // for(int i=0;i<r;i++){
        //     reverse(matrix[i].begin(),matrix[i].end());
        // }
    }
};

