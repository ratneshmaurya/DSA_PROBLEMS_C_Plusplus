
// O(log( Max - Min element ) * R * log C) --- time complexity 
// It is exactly same procedure that is used in finding median of 2d matrix sorted 
// row wise, as median ka mtlb bhi ki usse phle n/2 ements ho and uske aage bhi, 
// so yha ye concept lgega ki hme aesa number find krna jisse phle k-1 elements
// aa ske (i.e k-1 smaller elements) hence same algo lga skte

int kthSmallest(int matrix[MAX][MAX], int n, int k)
{
  //Your code here
        int r=n;
        int c=n;
        int startVal=matrix[0][0],endVal=matrix[r-1][c-1],midval;
        while(startVal<=endVal)
        {
            midval=startVal+ (endVal-startVal)/2;
            int ans=0;
            for(int i=0;i<r;i++){
                int l=0,h=c-1;
                while(l<=h){
                    int m=l+(h-l)/2;
                    if(matrix[i][m]<=midval) l=m+1; //important hai, see shifting left pointer to mid+1 agr equal(i.e matrix[i][m]=midVal) bhi hua hai toh
                    else h=m-1;
                }
                ans+=l;
            }
            if(ans<k) startVal=midval+1; // see ans<k hai not <= (as in case of median of 2d matrix)
            else endVal=midval-1;
        }
        return startVal;
}
