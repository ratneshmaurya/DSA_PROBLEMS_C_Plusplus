string isSubset(int a1[], int a2[], int n, int ma) {
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
        m[a1[i]]++;
    for(int i=0;i<ma;i++)
       if(m[a2[i]]<1){
           return "No";
       }
        return "Yes";
}