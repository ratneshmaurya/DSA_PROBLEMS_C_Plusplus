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