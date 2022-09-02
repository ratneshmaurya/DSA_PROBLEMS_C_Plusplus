// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Example 1:
// Input: s = "()"
// Output: true

class Solution {
public:
    bool isValid(string x) {
         // Your code here
        stack<char>temp;
       for(int i=0;i<x.length();i++){
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