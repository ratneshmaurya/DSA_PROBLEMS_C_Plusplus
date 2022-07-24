
//as we know we can use the element again if we take it , and if we 
//don't take it then we can't take it again any further
//thus we pass "n" instead of "n-1" in recursion call if we take that element i.e K[i] instead of K[i-1]


int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            //base condition.... basically we can initialise it before this two loops for simple understanding
            if (i == 0 || w == 0)
                K[i][w] = 0;
            
            //if we take it
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i][w - wt[i-1]], K[i - 1][w]);

            //if we don't take it
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}