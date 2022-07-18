class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>temp;
       for(int i=0;i<x.length();i++){

        // handles first case like if unput is this only --- '}'
           if(temp.empty()){
               temp.push(x[i]);
           }
           else if(temp.top()=='{' and x[i]=='}'||temp.top()=='(' && x[i]==')'||temp.top()=='[' && x[i]==']'){
               temp.pop();
           
           }
           else
           temp.push(x[i]);
       }
       if(temp.empty()){
           return true;
       }
       return false;
    }

};