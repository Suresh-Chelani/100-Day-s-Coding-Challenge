class Solution {
public:
    vector<string> lessThanTen = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> tenToNineteen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string helper(int num) {
        if (num < 10) return lessThanTen[num];

        if (num < 20) return tenToNineteen[num - 10];

        if (num < 100) return tens[num / 10] + (num % 10 != 0 ? " " + lessThanTen[num % 10] : "");

        if (num < 1000) return lessThanTen[num / 100] + " Hundred" + (num % 100 != 0 ? " " + helper(num % 100) : "");

        if (num < 1000000) 
            return helper(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + helper(num % 1000) : "");
        

        if (num < 1000000000) 
            return helper(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + helper(num % 1000000) : "");
        

        return helper(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + helper(num % 1000000000) : "");
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num);
    }
};

