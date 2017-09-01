class Solution {
public:
    int minSteps(int n) {
        int s = sqrt(n), ans = 0;
        for(int i=2; i<=s; ++i)
            while(n%i == 0) {
                ans += i;
                n /= i;
            }
        if(n>1) ans += n;
        return ans;
    }
};
