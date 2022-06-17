//=======================================================================================
// based on two pointer method
//O(N^2) time

class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int i,low,high,start=0,end=0;
        int maxLength=1; //becoz single character is always palindrome, we have to check for length>1
        for(i=1;i<s.size();i++){
            
            // for even length of palindrome substring
            low=i-1; 
            high=i;
            while(low>=0&& high<s.size() && s[low]==s[high]){
                if(((high-low)+1)>maxLength){
                    start=low;
                    end=high;
                    maxLength=end-start+1;
                }
                low--;
                high++;
            }
            
            // for odd length of palindrome substring
            low=i-1; 
            high=i+1;
            while(low>=0&& high<s.size() && s[low]==s[high]){
                if(((high-low)+1)>maxLength){
                    start=low;
                    end=high;
                    maxLength=end-start+1;
                }
                low--;
                high++;
            }
        }
        
        return s.substr(start,(end-start+1));
    }
};