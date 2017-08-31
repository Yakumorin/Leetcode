class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        string result = "";
        int last = 0;
        for(int i=1; i<=max(n, m); ++i) {
            int x, y;
            if(i > n) x = 0;
            else x = a[n - i] - '0';
            if(i > m) y = 0;
            else y = b[m - i] - '0';
            last = last + x + y;
            result = char(last%2 + '0') + result;
            last /= 2;
        }
        if(last) result = '1' + result;
        return result;
    }
};
