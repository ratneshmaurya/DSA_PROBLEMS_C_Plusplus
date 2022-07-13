
//this question is valid for if numbers are given negative and positive
//also right for if given all +ive number, but usme hum varibale size sliding window bhi lga skte simply

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,sum=0;
        if(nums.size()==0) return 0;
        unordered_map<int,int>m;  //stored sum till ith index and ith index
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) count++;
            
            if(m.find(sum-k)!=m.end()){
                count+=m[sum-k];
            }
            m[sum]++;
        }
        return count;
    }
};