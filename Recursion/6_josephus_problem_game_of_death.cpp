class Solution {
  public:
  int solve(vector<int>& v,int k,int idx){
        if(v.size()==1){
            return v[0];
        }
        idx=(idx+k)%v.size();
        v.erase(v.begin()+idx);
        solve(v,k,idx);
    }
    int safePos(int n, int k) {
        // code here
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int num=solve(v,k-1,0);
        return num;
    }
};