
// O(N3logN3) time
class Solution {
public:

    // simply using 3 pointer algorithm
    bool isInterleave(string s1, string s2, string s3) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        sort(s3.begin(),s3.end());
        if(s1.size()+s2.size()!= s3.size()) return false;
        else{
            int i=0,j=0,k=0;
            while(k<s3.size()){
                if(i<s1.size() && s1[i]==s3[k]) i++;
                else if(j<s2.size() && s2[j]==s3[k]) j++;
                else break;
                k++;
            }
            if(i<s1.size() || j<s2.size()){return false;}
            else return true;
        }
    }
};