// simple hai

class Solution {
public:
    int maxSubStr(string str){
        //if there is unequal number of 0's and 1's then it can't be possible
        // else every time possible irrespective of arrangement
        //just have to count max number of sequrnce
        
        int count0=0,count1=0,countSeq=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0') count0++;
            if(str[i]=='1')count1++;
            if(count0==count1)countSeq++;
        }
        //if at last count of 0 and 1 are not equal then return false;
        if(count0!=count1)return -1;
        else return countSeq;
    }
};