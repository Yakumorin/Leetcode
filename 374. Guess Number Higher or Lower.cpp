// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long l, r, mid;
        l = INT_MIN; r = INT_MAX;
        while(l <= r) {
            mid = (l+r) / 2;
            int x = guess(mid);
            if(x == 0) return mid;
            else if(x == 1) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
    }
};
