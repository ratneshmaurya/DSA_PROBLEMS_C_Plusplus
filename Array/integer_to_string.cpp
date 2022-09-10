
// Write a function to convert a given number into words.
// Example 1:
// Input:
// N = 438237764
// Output: forty three crore eighty two lakh 
// thirty seven thousand seven hundred and 
// sixty four
// Example 2:
// Input:
// N = 1000
// Output: one thousand
// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

class Solution{   
public:
    // strings at index 0 is not used, it is to make array
    // indexing simple
    string one[20] = { "", "one ", "two ", "three ", "four ",
                     "five ", "six ", "seven ", "eight ",
                     "nine ", "ten ", "eleven ", "twelve ",
                     "thirteen ", "fourteen ", "fifteen ",
                     "sixteen ", "seventeen ", "eighteen ",
                     "nineteen " };
     
    // strings at index 0 and 1 are not used, they is to
    // make array indexing simple
    string ten[10] = { "", "", "twenty ", "thirty ", "forty ",
                     "fifty ", "sixty ", "seventy ", "eighty ",
                     "ninety " };

    // n is 1- or 2-digit number
    string numToWords(int n, string s)
    {
        string str = "";
        // if n is more than 19, divide it
        if (n > 19)
            str += ten[n / 10] + one[n % 10];
        else
            str += one[n];
     
        // if n is non-zero i.e for handling if n=21, then crore lakh thousand hundred print 
        //hoga frji becoz n will be 0 in case of crore lakh thousand and hundred.
        if (n)
            str += s;
     
        return str;
    }
    
    string convertToWords(long n) {
         string out;
 
        // handles digits at ten millions and hundred
        // millions places (if any)
        out += numToWords((n / 10000000), "crore ");
     
        // handles digits at hundred thousands and one
        // millions places (if any)
        out += numToWords(((n / 100000) % 100), "lakh ");
     
        // handles digits at thousands and tens thousands
        // places (if any)
        out += numToWords(((n / 1000) % 100), "thousand ");
     
        // handles digit at hundreds places (if any)
        out += numToWords(((n / 100) % 10), "hundred ");

        //only runs if n is greater than 100 and usme tens or ones place pr digits ho kuchh eg-128,783
        if (n > 100 && n % 100)
            out += "and ";
     
        // handles digits at ones and tens places (if any)
        out += numToWords((n % 100), "");
       
        //Handling the n=0 case
        if(out=="")
        out = "zero";
     
        return out;
    }
};