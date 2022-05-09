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
// 
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