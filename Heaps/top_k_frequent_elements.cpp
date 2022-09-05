
//leetcode problem

// Given an integer array nums and an integer k, return the k most frequent elements. 
// You may return the answer in any order.
// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m1;  //stored number and its frequncy
        for(auto&i:nums){
            m1[i]++;
        }
        // map<int,int>m2;  //stored frequency order with number
        // for(auto&i:m1){
        //     m2[-1*i.second]=i.first; //blunder mistake, it can overlap the same frequency waale
        // }
        // //map<int,int>::iterator it=m2.begin();
        // int count=0;
        // vector<int>v;
        // for(auto i=m2.begin();i!=m2.end();i++){
        //     v.push_back(i->second);
        //     count++;
        //     if(count==k)break;
        // }
        // return v;
        
        priority_queue<pii,vector<pii>,greater<pii>>minH;
        for(auto&i:m1){
            minH.push({i.second,i.first});
            if(minH.size()>k)minH.pop();
        }
        vector<int>v;
        while(!minH.empty()){
            v.push_back(minH.top().second);
            minH.pop();
        }

        // reverse(v.begin(),v.end()); //// this line was important for this gfg condition,becoz our 
        //heap will store the minimum freq's element at top, but gfg wants a little different way
        return v;
    }
};