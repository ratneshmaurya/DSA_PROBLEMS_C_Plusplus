
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
// Example 1:
// Input: s = "aab"
// Output: "aba"
// Example 2:
// Input: s = "aaab"
// Output: ""

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(auto&i:s){
            m[i]++;
        }
        priority_queue<pair<int,char>>maxHeap;
        for(auto&i:m){
            maxHeap.push({i.second,i.first});
        }
        string temp="";
        pair<int,char> mostFreq,secondMostFreq;
        while(maxHeap.size()>1){
            mostFreq=maxHeap.top();
            maxHeap.pop();
            secondMostFreq=maxHeap.top();
            maxHeap.pop();
            temp+=mostFreq.second;
            temp+=secondMostFreq.second;
            // mostFreq.first-=1;
            // secondMostFreq.first-=1;
            if(--mostFreq.first>0) maxHeap.push(mostFreq);
            if(--secondMostFreq.first>0) maxHeap.push(secondMostFreq);
        }
        
        //if still last me aesa element bache jiski freq 2 bach rhi, then we can't form string
        if(maxHeap.size()!=0){
            if(maxHeap.top().first==1){
                temp+=maxHeap.top().second;
                return temp;
            }
            else{
                return "";
            }
        }
        
        return temp;
    }
};