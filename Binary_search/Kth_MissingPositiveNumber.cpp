// O(log n) solution

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k){
        int low=0,high=arr.size()-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid]-(mid+1)<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low+k;
    }
};




// O(N) solution -----
// assume 'k' is pointing to the answer that is kth missing num,
// if arr(i) becomes greater than 'k' then simply return value
//  of k as answer else if (arr[i] <= k) then do k++; and iterate krte rho for 
// next value of array,,,, k++ issiliye kiya becoz hme 5th missing chahiye than
//  and we got an element that is not missing hence we have to increase the 
// value of k so that 5th missing prr hi point kre rhe 'k'.
// 
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k){
//         for(auto i:arr){
//             if(i<=k)k++;
//             else break;
//         }
//         return k;
//     }
// };