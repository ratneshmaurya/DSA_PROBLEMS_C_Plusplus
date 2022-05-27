// O(N*M) time and [ O(N*M) space  if condition given ki 
// given matrix me change na kre else agr change kr skte 
// then O(1) space hoga bss  ]  --- DP approach yaad kr lo 
// concept clearing hai

// we start from bottom right, fill the last row and last col
//  first then we start filling from [n-2][n-2] and keep filling 
// in opposite direction.
// We pre-process the matrix such that index(i, j) stores
//  max of elements in matrix from (i, j) to (N-1, N-1) and 
// in the process keeps on updating maximum value found 
// so far. We finally return the maximum value.

// question --- Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b)
// over all choices of indexes such that both c > a and d > b.

//----------------------------------------------------------
//-----------------------------------------------------------
// NOTE ---  Copied from gfg, but added more comments at last for clarification !!!!!

int findMaxValue(int mat[][N])
{
    //stores maximum value
    int maxValue = INT_MIN;
 
    // maxArr[i][j] stores max of elements in matrix
    // from (i, j) to (N-1, N-1)
    int maxArr[N][N];
 
    // last element of maxArr will be same's as of
    // the input matrix
    maxArr[N-1][N-1] = mat[N-1][N-1];
 
    // preprocess last row
    int maxv = mat[N-1][N-1];  // Initialize max
    for (int j = N - 2; j >= 0; j--)
    {
        if (mat[N-1][j] > maxv)
            maxv = mat[N - 1][j];
        maxArr[N-1][j] = maxv;
    }
 
    // preprocess last column
    maxv = mat[N - 1][N - 1];  // Initialize max
    for (int i = N - 2; i >= 0; i--)
    {
        if (mat[i][N - 1] > maxv)
            maxv = mat[i][N - 1];
        maxArr[i][N - 1] = maxv;
    }
 
    // preprocess rest of the matrix from bottom
    for (int i = N-2; i >= 0; i--)
    {
        for (int j = N-2; j >= 0; j--)
        {
            // Update maxValue
            if (maxArr[i+1][j+1] - mat[i][j] > maxValue) // as hme mat(c, d) – mat(a, b) calculate krna
            //thus c,d both must be greter than a,b hence [i+1][j+1] se subtract krr ke dekh rhe [i][j]
                maxValue = maxArr[i + 1][j + 1] - mat[i][j];
 
            // set maxArr (i, j), i.e updating the dp matrix
            maxArr[i][j] = max(mat[i][j],
                               max(maxArr[i][j + 1],
                                   maxArr[i + 1][j]) );
        }
    }
 
    return maxValue;
}


// If we are allowed to modify of the matrix, we can avoid using extra space and use 
// input matrix instead.






// -------------------------------------------------------------------
// -------------------------------------------------------------------
// we can also do from top to bottom approach like this ----------


// The idea is to pre-process the given matrix MAT and store the minimum element encountered so far 
// in a new 2-D array. We take an extra 2-D matrix dp of size N x N and store the minimum element 
// encountered  from MAT[0][0] to MAT[i][j] at dp[i][j]. Then the maximum value of the function maxVal 
// is max(maxVa, MAT[i][j] - dp[i - 1][j - 1]).

 

// Here is the algorithm :

 

// We declare a 2-d matrix dp of size N x N.
// We initially fill dp as follows:
// dp[0][0] = MAT[0][0].
// We run a loop for i = 1 to N.
// d[i][0] = min(dp[i-1][0]’, ‘MAT[i][0])
// We run a loop for j = 1 to N.
// dp[0][j] = min(dp[0][j - 1], MAT[0][j])
// We declare a variable maxVal to store our final answer and initialize it with the minimum possible value.
// We run a loop for i = 1 to N:
// We run a loop for j = 1 to N:
// maxVal  = max(maxVal, MAT[i][j] - dp[i - 1][j - 1]).
// dp[i][j] = min(dp[i-1][j], min(dp[i][j-1],mat[i][j])).
// Finally, we return maxVal as our answer.