// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a 
// sum divisible by k.
// A subarray is a contiguous part of an array.
// Example 1:
// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// concept of prefix sum with all previous remainder
//this type of concept also used in subarray_Sum_Equals_To_K_having_(+ive)_and_(-ive)_numbers both


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>m; //store remainder with their frequency
        m[0]++; //i.e '0' remainder is already there
        int sum=0;
        int count=0;
        int rem;

        //at every time we take remainder and check whether this remainder already came or not, if yes it means
        //that there is sequence from that previous remainder index to this index that is divisible by K.

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=sum%k;

            //remember to handle -ive remainder,becoz our computer calculator always 
            //execute from 0th number in number line i.e if sum=-5 k=3 then rem by computer will be -2 not 1;

            if(rem<0){
                rem+=k;
            }
            if(m.find(rem)!=m.end()){
                //doing count+=m[rem], becoz suppose rem=5 had came 2 times earlier, it means we have got 2 
                //sequence earlier, but now if we got rem=5, it means we got 2 sequence more, that from first 
                //rem=5 index to current index, and second from second rem=5 index to current index.
                //hence adding '2' times(number of times this rem came earlier) in current value. 
                //so till now we have 4 seqeunce that have rem=5;
                //first from 0th index to first rem=5 index
                //second from first rem=5 index to second rem=5 index
                //third from first rem=5 index to third rem=5 index
                //fourth from second rem=5 index to third rem=5 index
                count+=m[rem];
                m[rem]++;
            }
            else{
                m[rem]++;
            }
        }
        return count;
    }
};