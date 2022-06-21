
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
                    swap(S[i],S[l]); // backtracking concept, becoz vapas se same kr de rha
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
