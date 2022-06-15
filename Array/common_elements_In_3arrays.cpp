class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
           //code here.
           vector<int>ans;
           
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