

//better approach

void printSubsequence(string input, string output)
{
    
    // if the input is empty print the output string
    if (i==input.length()) {
        cout << output << endl;
        return;
    }
 
    //include character and then pass
    printSubsequence(input,i+1, output + input[0]);
 
    //exclude character and then pass
    printSubsequence(input,i+1, output);
}




//in below approach we are using substr , it has time complexity O(N) hence donot use.

void printSubsequence(string input, string output)
{
    
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
 
    //include character and then pass
    printSubsequence(input.substr(1), output + input[0]);
 
    //exclude character and then pass
    printSubsequence(input.substr(1), output);
}