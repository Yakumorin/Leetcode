string number[]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
string tens[]={"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
class Solution {
    
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        return intToSting(num).substr(1);
    }
    string intToSting(int n) {
        if(n >= 1000000000)   return intToSting(n / 1000000000) + " Billion" + intToSting(n - 1000000000 * (n / 1000000000));
        else if(n >= 1000000) return intToSting(n / 1000000) + " Million" + intToSting(n - 1000000 * (n / 1000000));
        else if(n >= 1000)    return intToSting(n / 1000) + " Thousand" + intToSting(n - 1000 * (n / 1000));
        else if(n >= 100)     return intToSting(n / 100) + " Hundred" + intToSting(n - 100 * (n / 100));
        else if(n >= 20)      return string(" ") + tens[n / 10 - 2] + intToSting(n - 10 * (n / 10));
        else if(n >= 1)       return string(" ") + number[n];
        else return "";
    }
};
