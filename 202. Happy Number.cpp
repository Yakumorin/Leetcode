class Solution {
    int calc(int n) {
        int res=0;
        while(n) {
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_map<int, bool> table; 
        while(!table[n]) {
            table[n] = 1;
            if(n==1) return 1;
            n = calc(n);
        }
        return 0;
    }
};
