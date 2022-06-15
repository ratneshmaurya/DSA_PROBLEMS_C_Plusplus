
// O(n1+n2+n3) time
// O(1) space------------
// --------------------------------------------------------------------------

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0; 
            vector<int>ans;
            while(i<n1 && j<n2 && k<n3){
                
                if(A[i]==B[j] && B[j]==C[k]){
                    ans.push_back(A[i]);
                    i++;k++;j++;
                }
                else if(A[i]<B[j]) i++;
                
                else if(B[j]<C[k]) j++;
                
                else k++;
                
                // to move steps for preventing duplicates elements
                int a=A[i-1];
                while(A[i]==a)i++;
                int b=B[j-1];
                while(B[j]==b)j++;
                int c=C[k-1];
                while(C[k]==c)k++;
            }
            
            if(ans.size()==0) return {-1};
            
            else return ans;
        }

};



// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// O(n1+n2+n3) time
// O(n1+n2+n3) space
// --------------------------------------------------------------------------


class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
           //code here.
           vector<int>ans;
           

           //storing all elements in this map 
           unordered_map<int,int>mp;
           //initial count the freq
           mp[A[0]]++;
           mp[B[0]]++;
           mp[C[0]]++;

        // as given every element is sorted in all arrays so we can use A[i]!=A[i-1] for checking the duplicacy

           for(int i=1;i<n1;i++){
               //for preventing duplicate
               if(A[i]!=A[i-1])
               //count frequency for all element
                mp[A[i]]++;
           }
           for(int i=1;i<n2;i++){
               if(B[i]!=B[i-1])
               mp[B[i]]++;
           }
           for(int i=1;i<n3;i++){
               if(C[i]!=C[i-1])
                mp[C[i]]++;
           }
           for(auto it =mp.begin();it!=mp.end();it++){
               if(it->second>=3)// if a element is present if its freq will be >=3
                ans.push_back(it->first);
           }
           //sort the answer in ascending order
           sort(ans.begin(),ans.end());
           return ans;
        }

};