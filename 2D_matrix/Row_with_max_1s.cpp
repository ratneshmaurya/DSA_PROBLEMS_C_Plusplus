// O( R+C) in this we simply follow an approach that if we
// get '1' then we move to left and if we got '0' then we 
// move to next row for cheking whether any same column 
// of any row contains '1' or not. 

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans=-1,col=m-1;
	    for (int i=0;i<n;i++){
	        
	        for(int j=col;j>=0;j--){
	            
	            if(arr[i][j]==1){
	                ans=i;
	                col--; //next row (i.e for next i ) se reduced column se chalega 
	            }
	            else     //if we have 0 then skip that row. 
	            break;
	        }
	    }
	    return ans;
	}

};