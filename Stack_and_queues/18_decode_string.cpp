
// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string 
// inside the square brackets is being repeated exactly k times. Note that k 
// is guaranteed to be a positive integer.
// You may assume that the input string is always valid; there are no extra 
// white spaces, square brackets are well-formed, etc. Furthermore, you may 
// assume that the original data does not contain any digits and that digits 
// are only for those repeat numbers, k. For example, there will not be input 
// like 3a or 2[4].
// The test cases are generated so that the length of the output will never exceed 105.
// Example 1:
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:
// Input: s = "3[a2[c]]"
// Output: "accaccacc"



string decodeString(string s) {
        // stack<string>stk;
        // int i=s.size()-1;
        // string temp;
        // while(i>=0){
        //     if(s[i]!='['){
        //         string toStr="";
        //         toStr+=s[i];
        //         stk.push(toStr);
        //         i--;
        //     }
        //     else{
        //         temp="";
        //         while(stk.top()!="]"){
        //             temp+=stk.top();
        //             stk.pop();
        //         }
        //         stk.pop(); // remove that ']' bracket also;
        //         i--; //for fetching the number from given string
        //         char num=s[i];
        //         i--; // for pointing to left char
        //         int number=num-'0';
        //         //cout<<number;
        //         string ans=temp;
        //         while(number>1){
        //             ans+=temp;
        //             number--;
        //         }
        //         temp=ans;
        //         stk.push(temp);
        //     }
        // }
        // string ans="";
        // while(!stk.empty()){
        //     ans+=stk.top();
        //     stk.pop();
        // }
        // return ans;
        
        
        
        
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
        // When ']' is encountered, we need to start
        // decoding
        if (s[i] == ']') {
            string temp;
            while (!st.empty() && st.top() != '[') {
                // st.top() + temp makes sure that the
                // string won't be in reverse order eg, if
                // the stack contains 12[abc temp = c + "" =>
                // temp = b + "c" => temp = a + "bc"
                temp = st.top() + temp;
                st.pop();
            }
            // remove the '[' from the stack
            st.pop();
            string num;
            // remove the digits from the stack
            while (!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            int number = stoi(num);
            string repeat;
            for (int j = 0; j < number; j++)
                repeat += temp;
            for (char c : repeat)
                st.push(c);
        }
        // if s[i] is not ']', simply push s[i] to the stack
        else
            st.push(s[i]);
        }
        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }