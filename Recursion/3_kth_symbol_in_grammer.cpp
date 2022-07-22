class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 && K == 1)
            return 0;
        
        // We need to do some observation here:
        // 1 - Calculate the length of every row which is as below
        int mid = pow(2,(N-1))/2;
        
        // If the K lies in the first half, it is actually same as prev row
        if( K <= mid)
            return (kthGrammar(N-1, K));
        
            //Else it subtract the first half and then it is same as 
            //complement of the prev row
        else
            return  !kthGrammar(N-1, K-mid);
    }
};