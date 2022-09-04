// remeber this code handles duplicates also......

//method1-- using sets

class Solution
{
    private:
        void helper(string S,set<string>&output,int l,int r){
            if(l==r){
              output.insert(S);
            }
            else{
                for(int i=l;i<=r;i++){
                    swap(S[i],S[l]);
                    helper(S,output,l+1,r);
                    swap(S[i],S[l]);
                }
            }
        }
	public:
		vector<string>find_permutation(string S)
		{
		    set<string>output;  // becoz on gfg to avoid duplicate outputs and have output in ascending order.
		    helper(S,output,0,S.size()-1);
		    
		  //  now as we have to return the vector hence making vector from set;
		    vector<string>v(output.begin(),output.end());
		    return v;
		}
};



//---------------------------------------------------------------------------------------
//method2 - by sorting and skipping the same next caharcter
class Solution
{
	public:
    	void helpForPermute(string S, vector<string> &ans, int ind, int n){
    	    if(ind == n-1){
    	        ans.push_back(S);
    	        return;
    	    }
    	    for(int i=ind;i<n;i++){
    	        if(S[ind] == S[i] && ind != i)  continue;
    	        swap(S[ind], S[i]);
    	        helpForPermute(S, ans, ind+1, n);
    	        
    	    }
	    }
		vector<string> find_permutation(string S)
		{
		    vector<string> ans;
		    int n = S.size();
		    sort(S.begin(), S.end());
		    helpForPermute(S, ans, 0, n);
		    
		    return ans;
		}
};