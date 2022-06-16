// using sets ( store first whole string characters then push them back in str)
//  remember the order will be changed becoz tn set it is arranged in increasing order.
//  result will be in sorted lexiographical order.

char *removeDuplicate(char str[], int n)
{
    // create a set using string characters
    // excluding '\0'
    unordered_set<char>s (str, str+n-1);
 
    // print content of the set
    int i = 0;
    for (auto x : s)
       str[i++] = x;
    str[i] = '\0';
 
    return str;
}

