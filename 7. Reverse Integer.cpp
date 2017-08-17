class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        long long intmax;
        intmax = (1LL<<31)-1;
        int sign = (x>=0);
        while(x != 0) {
            res = res*10 + abs(x%10);
            x /= 10;
        }
        if(sign) {
            if(res > intmax) return 0;
            return res;
        } else {
            if(res > intmax+1) return 0;
            return -res;
        }
    }
};
