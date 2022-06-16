
// using two pointer ---  O(N) time ;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
};




// using recursion ---- O(N) time also;

class Solution {
    private:
    void helper(vector<char>&s,int i, int j){
        if(i>j){
            return;
        }
        swap(s[i],s[j]);
        i++;
        j--;
        helper(s,i,j);
    }
public:
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
};