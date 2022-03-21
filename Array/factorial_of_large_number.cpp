class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>v;
        v.push_back(1);
        int mul,carry=0;
        for(int i=1;i<=N;i++)
        {
            carry=0;
            for(int j=0;j<v.size();j++){
                mul=v[j]*i+carry;
                carry=mul/10;
                mul=mul%10;
                v[j]=mul;
            }
            while(carry){
               v.push_back(carry % 10);
               carry /= 10;
            }
        }
        reverse(v.begin(), v.end());
       return v;
    }
};