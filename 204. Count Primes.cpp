class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool>isPrime(n+1, 0);
        vector<int>prime;
        for(int i=2; i<n; ++i) {
            if(!isPrime[i]) {
                ans++;
                prime.push_back(i);
            }
            for(int j=0; j<prime.size(); ++j) {
                if(i * prime[j] > n) break;
                isPrime[i*prime[j]] = 1;
                if(i % prime[j] == 0) break;
            }
        }
        return ans;
    }
};
