int countRev (string str)
{
    // your code here
    stack<int>s;
    int ans=0;
    if(str.size()&1==1) return -1; //means odd length hai, so we can't balance
    for(int i=0;i<str.size();i++){
        
        //if very first element hai
        if(s.size()==0) s.push(str[i]);
        
        else{
            //if balance ho rha toh nikaal do
            if(!s.empty() && str[i]=='}' && s.top()=='{') s.pop();
            
            //else push krdo
            else s.push(str[i]);
        }
    }
    //if all balanced hokr nikl liye
    if(s.size()==0)return ans;
    
    int open=0,close=0;
    while(s.size()!=0){
        if(s.top()=='{'){
            open++; 
            s.pop();
        } 
        else{
            close++;
            s.pop();
        }
    }
    ans=((open+1)/2 +(close+1)/2);
    return ans;
    
}