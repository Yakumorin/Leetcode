class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long> q;
        q.push(-1);
        while(n) {
            long long top = q.top(); q.pop();
            n--;
            if(n == 0) return -top;
            if(top % 5 == 0) {
                q.push(top*5);
            } else if(top % 3 == 0) {
                q.push(top*5);
                q.push(top*3);
            } else {
                q.push(top*5);
                q.push(top*3);
                q.push(top*2);
            }
        }
    }
};
