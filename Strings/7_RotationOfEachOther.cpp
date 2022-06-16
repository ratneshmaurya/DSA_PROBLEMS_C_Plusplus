


// for O(n1+n2) time
// Make one string concanate
// and then do KMP algo of other string in this concanated string



// =======================================================================

// O(n1*n2) time
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int res=-1;
        for(int i=0;i<s.size();i++){
            
            // shifting process           
            int j,a=s[0];
            for(j=1;j<s.size();j++){
                s[j-1]=s[j];
            }
            s[j-1]=a;
            
           if(s==goal){ 
               res=0;
               break;
           }
        }
        if(res==0) return true;
        else return false;
    }
}


// or u can write ---
// this works same as above O(n1*n2) time

if (str1.length() != str2.length())
        return false;
 
       string temp = str1 + str1;
       return (temp.find(str2) != string::npos);
    
// ==========================================================================================

