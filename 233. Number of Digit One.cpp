class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        int ans = 0;
        long long base = 1;
        while(n>=base) {
            int index = (n/base)%10;
            ans += (n/base/10)*base;
            if(index == 1) ans += n%base + 1;
            if(index > 1) ans += base;
            base = base*10;
        }
        return ans;
    }
};
