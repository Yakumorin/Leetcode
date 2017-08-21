class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int t=x/2;
        int cnt=0;
        while(1) {
            if((long long)t*t<=x && (t+1LL)*(t+1LL) > x) return t;
            t = (t + (x/t))/2;
        }
    }
};
