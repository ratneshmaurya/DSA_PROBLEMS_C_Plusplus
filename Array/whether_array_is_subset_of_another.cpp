//subset hai, thus just make a map of one array , and traverse the array which 
//we have to check and see if any of its element is not found in the map then return false

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>store;
    for(int i=0;i<n;i++) store[a1[i]]++;
    
    for(int i=0;i<m;i++){
        if(store.find(a2[i])==store.end() || store[a2[i]]<0) return "No";
        else store[a2[i]]--;
    }
    return "Yes";
}