// O(32*R*log C) --- double binary search, firsrt we select 
// the number assuming it be the answwer then we check 
// it whether it is greater than half of elements or not, if 
// yes then it is answer else we again pick the another 
// number by binary search and check it with every row 
// using binary search.

#include<bits/stdc++.h>
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int startVal=0,endVal=2000,midval;
        int n=r*c;
        while(startVal<=endVal)
        {
            midval=startVal+ (endVal-startVal)/2;
            int ans=0;
            for(int i=0;i<r;i++){
                int l=0,h=c-1;
                while(l<=h){
                    int m=l+(h-l)/2;
                    if(matrix[i][m]<=midval) l=m+1;
                    else h=m-1;
                }
                ans+=l;
            }
            if(ans<=n/2) startVal=midval+1;
            else endVal=midval-1;
        }
        return startVal;
    }
};
