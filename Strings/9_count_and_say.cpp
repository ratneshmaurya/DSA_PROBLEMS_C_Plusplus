class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string temp,s="11";
        int i,j;
        
        // for n>2
        
        for(i=3;i<=n;i++)
        {
            temp="";
            s+="$";
            int p=1;
            
            // for every string made at each level             
            for(j=1;j<s.size();j++){
                
                //if same char na ho then abtk jo value thi usko store kro and dubara 
                //count var i.e p ko 1 kro
                if(s[j]!=s[j-1]){
                    temp=temp+to_string(p);
                    temp=temp+s[j-1];
                    p=1;
                }
                
                //if same varibale ho then siply count bdhao so that it can be used later
                else p++;
            }
            s=temp;
        }
        return s;
    }
};