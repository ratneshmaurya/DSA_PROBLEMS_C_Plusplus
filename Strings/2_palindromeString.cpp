int isPalindrome(char S[])
{
    // Your code goes here
    // int size=sizeof(S)/sizeof(S[0]);
    int size=strlen(S);
    int i=0,j=size-1;
    
    while(i<j){
        if(S[i++]!=S[j--]) return false;
    }
     return true;
}