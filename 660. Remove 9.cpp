class Solution {
    int f[20];
    int count(int n) {
        if(n<9) return n;
        vector<int> s;
        while(n) {
            s.push_back(n%10);
            n/=10;
        }
        int res = -1;
        for(int i=s.size()-1; i>=0; --i) {
            res += s[i]*f[i];
            if(s[i] == 9) break;
            if(i==0) ++res;
        }
        return res;
    }
public:
    int newInteger(int n) {
        f[0] = 1;
        for(int i=1; i<10; ++i) 
            f[i] = 9*f[i-1];
        int l=n, r=INT_MAX-1, ans;
        while(l<=r) {
            long long mid=((long long)l+r)/2;
            if(count(mid)<n) {
                l=mid+1;
            } else {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};
