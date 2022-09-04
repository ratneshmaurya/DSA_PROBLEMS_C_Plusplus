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
//method2 - by sorting and next permutation
// O(nlogn) due to sorting, can also be solved without recursion by next permutation 
// method, we will start from the sorted order, then we will apply next permutation in that order 
// for length! Times, becoz max number of permutation of a sequence is the factorial of length of sequence)