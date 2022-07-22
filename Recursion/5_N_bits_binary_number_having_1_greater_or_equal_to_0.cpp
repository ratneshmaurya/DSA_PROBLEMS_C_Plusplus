class Solution{
    private:
    void helper(vector<string>&ans,int n,string output,int one,int zero){
        if(n==0){
            ans.push_back(output);
            return;
        }
        //one is used for output sequence
        helper(ans,n-1,output+"1",one+1,zero);
        
        //zero will only be used, if the number of ones used were greater ,becoz we don't want
        //number of zero to be more in the prefix
        if(zero<one){
            helper(ans,n-1,output+"0",one,zero+1);
        }
    }
public:	
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string>ans;
	    helper(ans,N,"",0,0);
	    return ans;
	}
};