// copied from gfg

// Given a string str of lowercase characters, the task is to remove duplicates and return a resultant 
// string without modifying the order of characters in the original string.

// Input: str = "geeksforgeeks"
// Output: geksfor

// Input: str = "characters"
// Output: chartes

// The idea is to use bits of a counter variable to mark the presence of a character in the string. 
// To mark the presence of ‘a’ set 0th bit as 1, for ‘b’ set 1st bit as 1 and so on. If the corresponding 
// bit of character present in the original string is set to 0, it means it is the first occurrence of that 
// character, hence set its corresponding bit as 1 and keep on including the current character in the resultant string.


string removeDuplicatesFromString(string str)
{
 
    // keeps track of visited characters
    int counter = 0;
 
    int i = 0;
    int size = str.size();
 
    // gets character value
    int x;
 
    // keeps track of length of final string
    int length = 0;
 
    while (i < size) {
        x = str[i] - 97;
 
        // check if Xth bit of counter is unset
        if ((counter & (1 << x)) == 0) {
 
            str[length] = 'a' + x; // putting the corresponding character from starting
 
            // mark current character as visited
            counter = counter | (1 << x);
 
            length++;
        }
        i++;
    }
 
    return str.substr(0, length);  // only returning the resultant part of string;
}