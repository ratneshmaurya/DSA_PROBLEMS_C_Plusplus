class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,minIndex=-1,maxIndex=-1; //becoz we have to return substring
        int minlength=INT_MAX;
        unordered_map<char,int>m; //to store the characters to be searched
        for(auto &p:t) m[p]++;  //storing the pattern in map;
        int count=m.size();// this will tell us ki itne unique characters ka kaam ho gya pura.
        
        //sliding window concept
        while(j<s.size()) 
        {
            
            //now if freq of an element becomes 0 it means we have successfully find all the frequncy of this character in this window, now simply do count-- becoz we got one character ka kaam
            if(m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0) count--;
            }
            
            if(count>0) j++;
            
            else if(count==0) //means all characters ka kaam ho gya jitne search krne the.
            {
               //as extra frequncy bhi toh ho skti unn characters ki,hence decreasing window from left
                while(count==0)
                {
                   if(minlength> j-i+1)
                   {
                       minlength=j-i+1;
                       minIndex=i;
                       maxIndex=j;
                   }
                   
                   if(m.find(s[i])!=m.end())
                   {
                       m[s[i]]++;
                       if(m[s[i]]==1) count++; //means ek element or chahiyeabhi,as required element nikl gya window se bahar.
                   }
                    i++; //i is outside becoz it may possible ki m.find na mile , but hme to i ko aage krna hi hai increment for next window
                }
                j++;
            }
        }
        
        if(minlength==INT_MAX){ return "";}
        else {
            return s.substr(minIndex,maxIndex-minIndex+1);
        }
    }
};